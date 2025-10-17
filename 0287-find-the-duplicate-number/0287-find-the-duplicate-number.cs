public class Solution
{
    public int FindDuplicate(int[] nums)
    {
        Dictionary<int, int> m = new Dictionary<int, int>();

        foreach (int num in nums)
        {
            if (m.ContainsKey(num))
                m[num]++;
            else
                m[num] = 1;
        }

        foreach (var ele in m)
        {
            if (ele.Value > 1)
                return ele.Key;
        }

        return -1; // no duplicate found
    }
}
