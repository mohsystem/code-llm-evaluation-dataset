def countSmaller(nums):
    def count(t):
        res = []
        for x in t:
            i = bisect.bisect_left(t, x)
            res.append(i)
        return res
    t = sorted((x, i) for i, x in enumerate(nums))
    return count([x for _, i in t])