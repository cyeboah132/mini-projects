#include <iostream>
#include <string>
#include <ctime>

class DateTime
{
private:
    int year;
    int month;
    int day;

    int hour;
    int minute;
    int second;

    std::string formattedTime;

    friend class TimeManager;

public:
    int getYear()
    {
        return year;
    };
    int getMonth()
    {
        return month;
    };
    int getDay()
    {
        return day;
    };

    int getHour()
    {
        return hour;
    };
    int getMinute()
    {
        return minute;
    };
    int getSecond()
    {
        return second;
    };

    std::string getFormattedTime()
    {
        return formattedTime;
    };
};

class TimeManager
{
public:
    static DateTime getCurrentTime();
    void saveTime();
    void updateTime();
};

// functions

DateTime TimeManager::getCurrentTime()
{
    time_t currentTime = time(nullptr);
    tm *now = localtime(&currentTime);

    DateTime date;

    date.year = now->tm_year + 1900;
    date.month = now->tm_mon + 1;
    date.day = now->tm_mday;

    date.hour = now->tm_hour;
    date.minute = now->tm_min;
    date.second = now->tm_sec;

    char buffer[100];

    strftime(buffer, 100, "%d %B %Y, %I:%M %p", now);
    date.formattedTime = buffer;

    return date;
}

class Task
{
private:
    int id;
    std::string title;
    std::string description;
    DateTime createdAt = TimeManager::getCurrentTime();

public:
    enum class Status
    {
        current,
        completed,
        incomplete,
        deleted
    };
    Status status;

    Task(int id, std::string title, std::string description)
    {
        this->id = id;
        this->title = title;
        this->description = description;
        this->status = Status::current;
    }
};