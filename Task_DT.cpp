#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

class LogEntry {
public:
    int eventId;
    std::string requestId;
    std::string bannerId;
    double price;
};

class BannerStats {
public:
    double totalRevenue;
    std::unordered_map<int, int> eventCounts;

    BannerStats() : totalRevenue(0.0) {}
};

LogEntry parseLogEntry(const std::string& line) {
    LogEntry entry;
    std::istringstream iss(line);
    char eventType; // To hold 's' or 'c'
    iss >> eventType;
    iss.ignore(); // Ignore the delimiter (':' or ',')
    iss >> entry.eventId >> entry.requestId >> entry.bannerId >> entry.price;
    return entry;
}

void updateStatistics(BannerStats& stats, const LogEntry& entry) {
    if (entry.eventId == 1) {
        // For "sel" entries, add price to totalRevenue
        stats.totalRevenue += entry.price;
    }
    stats.eventCounts[entry.eventId]++;
}

int main() {
    std::string filename;
    std::cout << "Enter filename: ";
    getline(std::cin, filename);

    std::ifstream inputFile;
    inputFile.open(filename);

    if (!inputFile) {
        std::cerr << "Error: Unable to read the input file." << std::endl;
        return 1;
    }

    std::unordered_map<std::string, BannerStats> bannerMap;

    std::string line;
    while (std::getline(inputFile, line)) {
        LogEntry entry = parseLogEntry(line);
        if (entry.eventId != -1) {
            updateStatistics(bannerMap[entry.bannerId], entry);
        }
    }

    inputFile.close();

    std::ofstream outputFile("output.xml");

    outputFile << "<Banners>" << std::endl;
    for (const auto& entry : bannerMap) {
        outputFile << "  <Banner id=\"" << entry.first << "\" revenues=\"" << entry.second.totalRevenue << "\">" << std::endl;
        outputFile << "    <Events>" << std::endl;
        for (const auto& eventEntry : entry.second.eventCounts) {
            outputFile << "      <Event id=\"" << eventEntry.first << "\">" << eventEntry.second << "</Event>" << std::endl;
        }
        outputFile << "    </Events>" << std::endl;
        outputFile << "  </Banner>" << std::endl;
    }
    outputFile << "</Banners>" << std::endl;

    outputFile.close();

    return 0;
}
