#/usr/bin/python2.7
#!-*- encoding:utf-8 -*-
import time
import datetime
import calendar

# from time import strftime, localtime , mktime,strptime
# from datetime import timedelta, date,datetime


class Timetools(object):

    def __init__(self):
        self.year = time.strftime("%Y", time.localtime())
        self.mon = time.strftime("%m", time.localtime())
        self.day = time.strftime("%d", time.localtime())
        self.hour = time.strftime("%H", time.localtime())
        self.min = time.strftime("%M", time.localtime())
        self.sec = time.strftime("%S", time.localtime())

    @classmethod
    def today(self):
        return datetime.date.today()

    @classmethod
    def datetime(self):
        return time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())

    @classmethod
    def timestamp_to_str(self, a):
        return time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(a))

    @classmethod
    def getday_of_day(self, n=0):
        if(n < 0):
            n = abs(n)
            return datetime.date.today() - datetime.timedelta(days=n)
        else:
            return datetime.date.today() + tdatetime.imedelta(days=n)

    @classmethod
    def getdays_of_month(self, year, mon):
        return calendar.monthrange(year, mon)[1]

    @classmethod
    def getfirstday_of_month(self, year, mon):
        days = "01"
        if(int(mon) < 10):
            mon = "0" + str(int(mon))
        arr = (year, mon, days)
        return "-".join("%s" % i for i in arr)

    @classmethod
    def getlastday_of_month(self, year, mon):
        days = calendar.monthrange(year, mon)[1]
        mon = self.addzero(mon)
        arr = (year, mon, days)
        return "-".join("%s" % i for i in arr)

    @classmethod
    def get_firstday_month(self, n=0):
        (y, m, d) = getyearandmonth(n)
        d = "01"
        arr = (y, m, d)
        return "-".join("%s" % i for i in arr)

    @classmethod
    def addzero(self, n):
        nabs = abs(int(n))
        if(nabs < 10):
            return "0" + str(nabs)
        else:
            return nabs

    @classmethod
    def get_week_of_month(self, s="2016-05-24"):
        year = int(str(s).split("-")[0])
        month = int(str(s).split("-")[1])
        day = int(str(s).split("-")[2])
        end = int(datetime.datetime(year, month, day).strftime("%W"))
        begin = int(datetime.datetime(year, month, 1).strftime("%W"))
        return str(end - begin + 1)

    @classmethod
    def transfer_date_to_int(self, s="2016-05-24"):
        b = time.mktime(time.strptime(s, "%Y-%m-%d"))
        return b

    @classmethod
    def transfer_datetime_to_int(self, s="2016-05-27 16:05:32"):
        b = time.mktime(time.strptime(s, '%Y-%m-%d %H:%M:%S'))
        return b

    @classmethod
    def get_before_minute(self, t=0):
        res = (datetime.datetime.now() - datetime.timedelta(minutes=t +
                                                            (60 * 24 * 2))).strftime("%Y-%m-%d %H:%M:%S")
        return res

    @classmethod
    def get_now_month_date_list(self):
        r = []
        year = time.strftime("%Y", time.localtime())
        mon = time.strftime("%m", time.localtime())
        day = time.strftime("%d", time.localtime())
        for i in xrange(1, int(day)):
            r.append(year + "-" + mon + "-" + str(i))
        return r[:-1]

    @classmethod
    def get_month_date_list(self, s):
        year = int(s.split("-")[0])
        month = int(s.split("-")[1])
        r = []
        d = range(int(calendar.monthrange(year, month)[1]) + 1)[1:]
        for dd in d:
            r.append(str(year) + "-" + str(month) + "-" + str(dd))
        return r

    @classmethod
    def print_datetime(self, begintime, endtime):
        res = []
        begintime_datetime = datetime.datetime.strptime(
            begintime, "%Y-%m-%d %H:%M:%S")
        endtime_datetime = datetime.datetime.strptime(
            endtime, "%Y-%m-%d %H:%M:%S")
        diffSeconds = (endtime_datetime -
                       begintime_datetime).total_seconds() / 60 + 1
        for i in range(int(diffSeconds)):
            res.append((endtime_datetime - datetime.timedelta(minutes=i)
                        ).strftime("%Y-%m-%d %H:%M:%S"))
        return res

if __name__ == '__main__':
    t = Timetools()
    # 获取今天日期，2016-07-13
    print t.today()
    # 获取当前时间，2016-07-13 14:56:47
    print t.datetime()
    # 将时间戳转换成日期
    print t.timestamp_to_str(1469607219.12)
    # 获取前n天日期，2016-07-04
    print t.getday_of_day(-9)
    # 获取某个月一共多少天，30
    print t.getdays_of_month(2016, 6)
    # 获取某个月第一天日期，2016-06-01
    print t.getfirstday_of_month(2016, 6)
    # 获取某个月最后一天日期，2016-06-30
    print t.getlastday_of_month(2016, 6)
    print t.getlastday_of_month(2016, 12)

    # 获取第几周，3
    print t.get_week_of_month("2016-07-13")
    # 将日期转换成时间戳，1468339200.0
    print t.transfer_date_to_int("2016-07-13")
    # 将时间转换成时间戳，1468383300.0
    print t.transfer_datetime_to_int("2016-07-13 12:15:00")
    # 打印n分钟前的时间，2016-07-11 14:32:47
    print t.get_before_minute(24)
    # 打印这个月的所有天的日期（不完整）
    print t.get_now_month_date_list()
    # 打印某个月的所有天的日期
    print t.get_month_date_list("2016-06")

    # 打印某段时间内的每一分钟
    print t.print_datetime("2016-06-11 12:45:00", "2016-06-11 12:55:00")

    print time.localtime()
    print time.strftime("", time.localtime())

