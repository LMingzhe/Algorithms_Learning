//2. 使用一个map和priority_queue实现一个可以更新优先级的priority_queue，MutablePriorityQueue
/**
 * @brief 
 * std::priority_queue是一个非侵入式容器，我们无法随意修改内部元素的优先级
 * 我们可以通过一个std::unordered_map辅助，实现侵入式修改
 */
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>

struct MutablePriorityQueue
{
    using Identity = std::string;
    using Priority = int;
    struct Node
    {
        Identity id;
        Priority priority;
    };

    /**
    * @brief 插入一个Node
    * 如果Node::id已经存在，则表示更新对应Node的priority
    */
    void push(Node node)
    {
        if (umap.find(Node.id) != umap.end())
        {
            umap[node.id] = node.priority; // 在umap中修改优先级
            std::vector<Node> temp; // 暂存弹出的Node
            while (!pri_que.empty())
            {
                Node cur = pri_que.top();
                pri_que.pop();
                if (cur.id == node.id)
                {
                    cur.priority = umap[cur.id]; // 修改Node优先级
                    temp.push_back(cur);
                    break;
                } 
                else
                {
                    temp.push_back(cur);
                }
            }
            for (const auto& node : temp)
            {
                pri_que.push(node);
            }
        } 
        else 
        {
            pri_que.push(node);
            umap[node.id] = node.priority;
        }
    }

    /**
    * @brief 访问当前Priority最大的Node
    * 
    * @return Node
    */
    Node top() const
    {
        // TODO:
        return pri_que.top();
    }

    /**
    * @brief 移除当前Priority最大的Node
    * 
    */
    void pop()
    {
        // TODO:
        Node removedNode = pri_que.top();
        pri_que.pop();
        umap.erase(removedNode.id);
    }

private:
    // TODO:
    class myComparison
    {
    public:
        bool operator()(const Node& left, const Node& right)
        {
            return left.priority < right.priority;
        }
    };
    std::priority_queue<Node, std::vector<Node>, myComparison> pri_que;
    std::unordered_map<Identity, Priority> umap;
};