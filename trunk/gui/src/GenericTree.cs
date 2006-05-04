namespace SNAP {
    internal class GenericTree<TKey, TValue> {

        public class NodeCollection : System.Collections.Generic.SortedDictionary<TKey, Node> {
        }
        public class Node {
            public Node Parent = null;
            public TValue Value = default(TValue);
            public NodeCollection ChildNodes;

            /// <summary>
            /// Initializes a new instance of the <see cref="T:Node"/> class.
            /// </summary>
            public Node() {
                ChildNodes = new NodeCollection();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="T:Node"/> class.
            /// </summary>
            /// <param name="parent">The parent.</param>
            public Node(Node parent) {
                Parent = parent;
                ChildNodes = new NodeCollection();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="T:Node"/> class.
            /// </summary>
            /// <param name="parent">The parent.</param>
            /// <param name="value">The value.</param>
            /// <param name="childNodes">The child nodes.</param>
            protected Node(Node parent, TValue value, NodeCollection childNodes) {
                Parent = parent;
                Value = value;
                ChildNodes = childNodes;
            }

            /// <summary>
            /// Counts the descendents.
            /// </summary>
            /// <returns></returns>
            public int CountDescendents() {
                int count = 0;
                foreach (Node node in ChildNodes.Values) {
                    count += 1 + node.CountDescendents();
                }

                return count;
            }

            /// <summary>
            /// Gets the depth.
            /// </summary>
            /// <value>The depth.</value>
            public int Depth {
                get {
                    if (Parent == null)
                        return 0;
                    else
                        return Parent.Depth + 1;
                }
            }
        }

        public readonly NodeCollection RootNodes = new NodeCollection();
    }
}