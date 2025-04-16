#include <gtest/gtest.h>
#include <filesystem>
#include "../include/FileTracker.h"

TEST(FileTrackerTest, CollectsFilesWithModificationTimes) {
    std::string testDir = "test_dir";
    std::filesystem::create_directory(testDir);

    std::string testFile = testDir + "/sample.txt";
    std::ofstream(testFile) << "test content";

    auto result = getFilesWithModifiedTimes(testDir);

    EXPECT_TRUE(result.find(testFile) != result.end());

    std::filesystem::remove(testFile);
    std::filesystem::remove(testDir);
}