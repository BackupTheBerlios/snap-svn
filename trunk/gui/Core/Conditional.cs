using System;
using System.Collections.Generic;
using System.Text;

namespace SNAP.Scripts.Logic
{
    #region Conditional

    public abstract class Conditional
    {
        #region abstract

        public abstract bool Process(object input);

        /// <summary>
        /// Gets the sub terms.
        /// </summary>
        /// <value>The subterms.</value>
        public abstract IList <Conditional> SubTerms
        {
            get;
        }

        /// <summary>
        /// Accepts the specified visitor.
        /// </summary>
        /// <param name="visitor">The visitor.</param>
        public void Accept(IVisitor visitor)
        {
            visitor.GetType().GetMethod("Visit", new System.Type[] { this.GetType() }).Invoke(visitor, new object[] { this });
        }

        public interface IVisitor
        {
        }

        #endregion abstract

        #region interface
        /// <summary>
        /// Ands the specified conditionals.
        /// </summary>
        /// <param name="conditionals">The conditionals.</param>
        /// <returns></returns>
        public Conjunction And(params Conditional[] conditionals)
        {
            Conjunction conjunction = new Conjunction();
            conjunction.SubTerms.Add (this);
            foreach (Conditional c in conditionals)
                conjunction.SubTerms.Add(c);
            return conjunction;
        }
        /// <summary>
        /// Ors the specified conditionals.
        /// </summary>
        /// <param name="conditionals">The conditionals.</param>
        /// <returns></returns>
        public Disjunction Or(params Conditional[] conditionals)
        {
            Disjunction disjunction = new Disjunction();
            disjunction.SubTerms.Add(this);
            foreach (Conditional c in conditionals)
                disjunction.SubTerms.Add(c);

            return disjunction;
        }
        /// <summary>
        /// Nots this instance.
        /// </summary>
        /// <returns></returns>
        public Negation Not()
        {
            return new Negation(this);
        }

        #endregion interface
    }

    #endregion Conditional

    #region Conjunction

    public class Conjunction : Conditional
    {
        #region Properties

        private readonly List<Conditional> _conditionals = new List<Conditional>();

        public override IList<Conditional> SubTerms
        {
            get
            {
                return _conditionals;
            }
        }

        #endregion Properties

        #region implementation
        /// <summary>
        /// Processes the specified input.
        /// </summary>
        /// <param name="input">The input.</param>
        /// <returns></returns>
        public override bool Process(object input)
        {
            foreach (Conditional conditional in SubTerms)
            {
                if (!conditional.Process(input))
                    return false;
            }
            return true;
        }

        /// <summary>
        /// Returns a <see cref="T:System.String"/> that represents the current <see cref="T:System.Object"/>.
        /// </summary>
        /// <returns>
        /// A <see cref="T:System.String"/> that represents the current <see cref="T:System.Object"/>.
        /// </returns>
        public override string ToString()
        {
            StringBuilder buffer = new StringBuilder();
            buffer.Append("(");
            buffer.Append(SubTerms[0]);

            for (int i = 1; i < SubTerms.Count; ++i)
            {
                buffer.Append(" And ");
                buffer.Append(SubTerms[i]);
            }
            buffer.Append(")");
            return buffer.ToString();
        }

        #endregion implementation
    }

    #endregion Conjunction

    #region Disjunction

    public class Disjunction : Conditional
    {
        #region Properties
        private readonly List<Conditional> _conditionals = new List<Conditional>();

        public override IList<Conditional> SubTerms
        {
            get
            {
                return _conditionals;
            }
        }
        #endregion Properties

        #region Implementation
        /// <summary>
        /// Processes the specified input.
        /// </summary>
        /// <param name="input">The input.</param>
        /// <returns></returns>
        public override bool Process(object input)
        {
            foreach (Conditional conditional in SubTerms)
            {
                if (conditional.Process(input))
                    return true;
            }
            return false;
        }

        /// <summary>
        /// Returns a <see cref="T:System.String"/> that represents the current <see cref="T:System.Object"/>.
        /// </summary>
        /// <returns>
        /// A <see cref="T:System.String"/> that represents the current <see cref="T:System.Object"/>.
        /// </returns>
        public override string ToString()
        {
            StringBuilder buffer = new StringBuilder();
            buffer.Append("(");
            buffer.Append(SubTerms[0]);

            for (int i = 1; i < SubTerms.Count; ++i)
            {
                buffer.Append(" Or ");
                buffer.Append(SubTerms[i]);
            }
            buffer.Append(")");
            return buffer.ToString();
        }
        #endregion Implementation
    }

    #endregion Disjunction

    #region Negation

    public class Negation : Conditional
    {
        #region Constructors
        /// <summary>
        /// Initializes a new instance of the <see cref="Negation"/> class, with a null negated term.
        /// A Negation with a null negated term always returns false.
        /// </summary>
        public Negation()
        {
            Negated = null;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="Negation"/> class.
        /// </summary>
        /// <param name="c">The c.</param>
        public Negation(Conditional c)
        {
            Negated = c;
        }
        #endregion Constructors

        #region Properties
        public Conditional Negated;

        public override IList<Conditional> SubTerms
        {
            get
            {
                return new Conditional[] { Negated };
            }
        }

        #endregion Properties

        #region Implementation
        /// <summary>
        /// Processes the specified input.
        /// </summary>
        /// <param name="input">The input.</param>
        /// <returns></returns>
        public override bool Process(object input)
        {
            return !Negated.Process(input);
        }

        public override string ToString()
        {
            StringBuilder buffer = new StringBuilder();
            buffer.Append("(Not ");
            buffer.Append(Negated);
            buffer.Append(")");
            return buffer.ToString();
        }
        #endregion Implementation
    }

    #endregion Negation

}
