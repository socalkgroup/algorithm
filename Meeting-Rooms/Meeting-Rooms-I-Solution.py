class Solution(object):
    def canAttendMeetings(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: bool
        """
        if len(intervals) < 2:
            return True
        else:
            intervals = sorted(intervals, key=lambda x: x[0])
            for p, q in zip(intervals, intervals[1:]):
                if q[0] < p[1]:
                    return False
            return True
