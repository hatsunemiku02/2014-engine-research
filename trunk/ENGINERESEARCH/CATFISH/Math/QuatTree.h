#include <vector>

namespace Math
{
	template <typename T>
	class QuatTree
	{
	public:
		struct Node
		{
		public:
			Node()
			{
				m_Children.resize(4);
				m_Children[0] = 0;
				m_Children[1] = 0;
				m_Children[2] = 0;
				m_Children[3] = 0;
			}
			~Node()
			{
				delete m_Children[0];
				delete m_Children[1];
				delete m_Children[2];
				delete m_Children[3];
				m_Children.clear();
			}
			void InitChild()
			{
				m_Children[0] = new Node();
				m_Children[1] = new Node();
				m_Children[2] = new Node();
				m_Children[3] = new Node();
			}
			void SetContent(const T& content)
			{
				m_Content = content;
			}
			T& GetContent()
			{
				return m_Content;
			}
			void SetChild(int i,const Node* n)
			{
				m_Children[i] = n
			}
			Node* GetChild(int i)
			{
				return m_Children[i];
			}
		private:
			T m_Content;
			std::vector<Node*> m_Children;

		};


	public:
		QuatTree()
		{
			m_Depth = 0;
			m_pRoot = 0;
		}
		QuatTree(int depth)
		{
			m_Depth = depth;
			m_pRoot = new Node();
			InitQuatTree(0,m_pRoot);
		}

		void InitQuatTree(int depth)
		{
			m_Depth = depth;
			m_pRoot = new Node();
			InitQuatTree(0,m_pRoot);
		}
		~QuatTree()
		{

		}
		Node* GetRoot()
		{
			return m_pRoot;
		}
	protected:
		Node* m_pRoot;
		int m_Depth;
	private:

		void InitQuatTree(int depth,Node* pNode)
		{
			depth++;
			if(depth>=m_Depth)
			{
				return;
			}
			pNode->InitChild();
			for(int i = 0;i<4;i++)
			{
				Node* pChild = pNode->GetChild(i);
				InitQuatTree(depth,pChild);
			}
		}

	};
}
