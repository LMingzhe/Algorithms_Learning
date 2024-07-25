#include <iostream>
#include <mutex>
#include <map>
#include <set>

// 3. 请完成下面的内存池(TODO)，减少运行时动态内存分配，需要保证线程安全
struct MemEntry
{
    //如果>capacity, 开辟一块大小为size的内存
    size_t alloc(size_t size);

    //释放当前内存
    void free();

    //获取当前内存指针
    uint8_t *data();

    size_t capacity{0};

    uint8_t *mem{nullptr};
};

struct DataMem
{
    uint64_t seq;
    size_t size;
    size_t capacity;
    uint8_t *data;
};

struct DataMemPool
{
    //获取DataMemPool单例
    static DataMemPool &instance()
    {
        //TODO
        static DataMemPool pool;
        return pool;
    }

    //申请一个DataMem
    DataMem alloc(size_t size)
    {
        //TODO
        return getDataMem();
    }

    //返还一个DataMem
    void free(DataMem &data_mem)
    {
        //TODO
        std::lock_guard<std::mutex> lock(mtx);
        free_seqs[data_mem.seq].insert(data_mem.capacity);
    }

    //获取内存池当前总大小Bytes
    uint64_t totalSize()
    {
        //TODO
        std::lock_guard<std::mutex> lock(mtx);
        uint64_t totalSize = 0;
        for (auto it = mem_entries.begin(); it != mem_entries.end(); ++it)
        {
            totalSize += *it->second.capacity;
        }
        return totalSize;
    }

    //释放内存池所有资源
    void destroy()
    {
        //TODO
        std::lock_guard<std::mutex> lock(mtx);
        for (auto it = mem_entries.begin(); it != mem_entries.end(); ++it)
        {
            *it->second.free();
            mem_entries.erase(it);
        }
        mem_entries.clear();
        free_seqs.clear();
    }

private:
    //扩展内存池，从内存里开辟一个新的内存空间
    uint64_t expandMemEntries(size_t size)
    {
        //TODO
        std::lock_guard<std::mutex> lock(mtx);
        MemEntry newEntry;
        newEntry.alloc(size);
        mem_entries[++cur_seq] = newEntry;
        free_seqs[++cur_seq].insert(size);
        return cur_seq;
    }

    //获取一个可用且满足size要求的DataMem
    DataMem getDataMem(uint64_t seq, size_t size)
    {
        //TODO
        std::lock_guard<std::mutex> lock(mtx);
        uint64_t free_size = 0; // 序号为 seq 的内存块剩余内存大小
        for (auto it = free_seqs[seq].begin(); it != free_seqs[seq].end(); ++it)
        {
            free_size += *it;
        }

        if (free_size < size) // 内存足够
        {
            uint64_t mem_to_use = 0;
            // 更新 free_seqs
            for (auto it = free_seqs[seq].beginl; it != free_seqs[seq].end(); ++it)
            {
                mem_to_use += *it;
                free_seqs[seq].erase(it);
                if (mem_to_use >= size) break;
            }
            return DateMem(seq, 0, mem_to_use, mem_entries[seq].data);
        }
        else // 内存不足，申请新内存块
        {
            expandMemEntries(size);
            free_seqs[cur_seq].clear();
            return DataMem(cur_seq, 0, size, MemEntry[cur_seq].data);
        }

    }
    std::mutex mtx;
    uint64_t cur_seq = -1; // 内存块序号
    std::map<uint64_t, std::set<uint64_t>> free_seqs; // 空闲内存
    std::map<uint64_t, MemEntry> mem_entries; // 内存条目
};