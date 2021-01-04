class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        sortedIntervals = sorted(intervals)
        mergedIntervals = sortedIntervals[:1]

        for interval in sortedIntervals[1:]:
            if interval[0] <= mergedIntervals[-1][1]:
                mergedIntervals[-1][1] = max(mergedIntervals[-1][1], interval[1])
            else:
                mergedIntervals.append(interval)

        return mergedIntervals
