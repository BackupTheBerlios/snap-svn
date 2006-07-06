using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace SNAP.Scripts
{
    #region class ConditionalStep

    internal class ConditionalStep : IStep
    {
        private readonly Logic.Conditional _if;
        private readonly IStep _then;
        private readonly IStep _else;

        public ConditionalStep(Logic.Conditional ifConditional, CompositeStep thenStep, CompositeStep elseStep)
        {
            _if = ifConditional;
            _then = thenStep;
            _else = elseStep;
        }


        #region IStep Members

        /// <summary>
        /// Executes the step for the specified resource.
        /// </summary>
        /// <param name="resource">The resource.</param>
        public void Execute(SNAP.Scripts.IStepArgs args)
        {
            if (_if.Process(args))
                _then.Execute(args);
            else if (_else != null)
                _else.Execute(args);
        }


        #endregion
    }

    #endregion class ConditionalStep

    #region EqualityConditional

    public class EqualityConditional : SNAP.Scripts.Logic.Conditional
    {
        public readonly string A;
        public readonly string B;

        public EqualityConditional(string a, string b)
        {
            A = a;
            B = b;
        }
        public override bool Process(object actual)
        {
            return Process((IStepArgs)actual);
        }
        public bool Process(IStepArgs args)
        {
            string a = SNAP.Scripts.Util.Interpret(args.MyScript, A, args.MyResource);
            string b = SNAP.Scripts.Util.Interpret(args.MyScript, B, args.MyResource);
            return a.Equals(b);
        }
        public override IList<Logic.Conditional> SubTerms
        {
            get { throw new Exception("The method or operation is not implemented."); }
        }
    }

    #endregion EqualityConditional
}
