#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <string_view>

class Time {

private:
    int mHours, mMinutes, mSeconds;
public:
    Time(int hours, int minutes, int seconds) : 
        mHours(hours), mMinutes(minutes), mSeconds(seconds) {}

    Time(std::string_view s) {
        std::stringstream ss(s.data());
        char c;
        ss >> mHours >> c >> mMinutes >> c >> mSeconds;
    }

    Time() {
        std::cout << "Enter the time in the format HH:MM:SS: ";
        std::string input;
        std::getline(std::cin, input);
        std::stringstream ss(input);
        char c;
        ss >> mHours >> c >> mMinutes >> c >> mSeconds;
    }

    Time operator+(Time b) const {
        int seconds = mSeconds + b.mSeconds;
        int minutes = mMinutes + b.mMinutes + seconds / 60;
        int hours = mHours + b.mHours + minutes / 60;
        seconds %= 60;
        minutes %= 60;
        hours %= 24;
        return Time(hours, minutes, seconds);
    }

    int hours() const { return mHours; }
    int minutes() const { return mMinutes; }
    int seconds() const { return mSeconds; }
    friend std::ostream& operator << (std::ostream& out, Time t);
};

std::ostream& operator<<(std::ostream& out, Time t) {
    out << t.mHours << ":" << t.mMinutes << ":" << t.mSeconds;
    return out;
}

std::vector<Time> getTimesFromString(std::string_view s) {
    std::vector<Time> times;
    std::stringstream ss(s.data());
    std::string token;
    while (std::getline(ss, token, ' ')) {
        times.emplace_back(token);
    }
    return times;
}

Time sumTimes(const std::vector<Time>& v) {

    Time sum(0, 0, 0);
    for (const auto& t : v) {
        sum = sum + t;
    }
    return sum;
}

int main() {
    Time t1, t2;
    std::vector<Time> times = { t1, t2 };
    std::cout << "Amount of time: " << sumTimes(times) << std::endl;
    return 0;
}