#include <gtest/gtest.h>
#include "Task_DT.cpp" 

TEST(LogEntryTests, ParseLogEntryTest) {

    LogEntry entry = parseLogEntry("Event1,Request1,Banner1,10.5");
    ASSERT_EQ(entry.eventId, 1);
    ASSERT_EQ(entry.requestId, "Request1");
    ASSERT_EQ(entry.bannerId, "Banner1");
    ASSERT_EQ(entry.price, 10.5);
}

TEST(BannerStatsTests, UpdateStatisticsTest) {

    BannerStats stats;
    LogEntry entry;
    entry.eventId = 1;
    entry.price = 10.0;
    updateStatistics(stats, entry);
    ASSERT_EQ(stats.totalRevenue, 10.0);
    ASSERT_EQ(stats.eventCounts[1], 1);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
