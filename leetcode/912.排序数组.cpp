/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 *
 * https://leetcode-cn.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (53.05%)
 * Likes:    97
 * Dislikes: 0
 * Total Accepted:    46.2K
 * Total Submissions: 78.1K
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 * 
 * 
 */

// @lc code=start
class Solution {

template <typename RAIt>
constexpr RAIt m_next(RAIt it,
                    typename std::iterator_traits<RAIt>::difference_type n = 1)
{
    return it + n;
}

template <typename RAIt>
constexpr auto m_distance(RAIt first, RAIt last)
{
    return last - first;
}

template<class ForwardIt1, class ForwardIt2>
constexpr void m_iter_swap(ForwardIt1 a, ForwardIt2 b)
{
    auto temp = std::move(*a);
    *a = std::move(*b);
    *b = std::move(temp);
}

template<class InputIt, class UnaryPredicate>
constexpr InputIt m_find_if_not(InputIt first, InputIt last, UnaryPredicate q)
{
    for (; first != last; ++first) {
        if (!q(*first)) {
            return first;
        }
    }
    return last;
}

template<class ForwardIt, class UnaryPredicate>
constexpr ForwardIt m_partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    first = m_find_if_not(first, last, p);
    if (first == last) return first;

    for(ForwardIt i = m_next(first); i != last; ++i){
        if(p(*i)){
            m_iter_swap(i, first);
            ++first;
        }
    }
    return first;
}



template<class RAIt, class Compare = std::less<>>
constexpr void quick_sort(RAIt first, RAIt last, Compare cmp = Compare{})
{
    auto const N = m_distance(first, last);
    if (N <= 1) return;
    auto const pivot = *m_next(first, N / 2);
    auto const middle1 = m_partition(first, last, [=](auto const& elem){
        return cmp(elem, pivot);
    });
    auto const middle2 = m_partition(middle1, last, [=](auto const& elem){
        return !cmp(pivot, elem);
    });
    quick_sort(first, middle1, cmp); // assert(std::is_sorted(first, middle1, cmp));
    quick_sort(middle2, last, cmp);  // assert(std::is_sorted(middle2, last, cmp));
}


public:
    vector<int> sortArray(vector<int>& nums) {
    quick_sort(std::begin(nums), std::end(nums));
    return nums;
    }
    
};


// @lc code=end

