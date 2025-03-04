#pragma once
#include <functional>
#include <chrono>
#include <cstdio>
#include "../raylib/include/raylib.h"

class Condition
{
public:
    Condition() {}
    ~Condition() {}
    virtual bool is_true()
    {
        return true;
    }
    virtual bool to_delete()
    {
        return false;
    }
};

typedef std::chrono::time_point<std::chrono::steady_clock> TimePoint;
class TimeCondition : public Condition
{
private:
    TimePoint time;

public:
    TimeCondition(TimePoint time) : time(time) {}
    ~TimeCondition() {}
    bool is_true() override
    {
        return time < std::chrono::steady_clock::now();
    }
    bool to_delete() override
    {
        return is_true();
    }
};

template <KeyboardKey key>
class KeyTrigger
{
public:
    class IsDownCondition : public Condition
    {
    public:
        IsDownCondition() {}
        ~IsDownCondition() {}

        bool is_true() override
        {
            return IsKeyDown(key);
        }
        bool to_delete() override
        {
            return false;
        }
    };
    class IsPressedCondition : public Condition
    {
    public:
        IsPressedCondition() {}
        ~IsPressedCondition() {}

        bool is_true() override
        {
            return IsKeyPressed(key);
        }
        bool to_delete() override
        {
            return false;
        }
    };
    class IsUpCondition : public Condition
    {
    public:
        IsUpCondition() {}
        ~IsUpCondition() {}

        bool is_true() override
        {
            return IsKeyUp(key);
        }
        bool to_delete() override
        {
            return false;
        }
    };
    class IsReleasedCondition : public Condition
    {
    public:
        IsReleasedCondition() {}
        ~IsReleasedCondition() {}

        bool is_true() override
        {
            return IsKeyReleased(key);
        }
        bool to_delete() override
        {
            return false;
        }
    };
};

struct Command
{
    Condition *condition;
    std::function<void()> callback;
    // a callback to a func that will get defined like:
    // void callback() {}
};

class Subsystem;
class CommandScheduler
{
private:
    std::vector<Command> task_queue;
    std::vector<Subsystem *> subsystems;

public:
    void add_command(Command cmd)
    {
        task_queue.push_back(cmd);
    }
    void add_subsystem(Subsystem *system)
    {
        subsystems.push_back(system);
    }
    void periodic();
    CommandScheduler() {}
    ~CommandScheduler() {}
};

class Subsystem
{
private:
public:
    Subsystem(CommandScheduler *scheduler)
    {
        scheduler->add_subsystem(this);
    }
    ~Subsystem() {}

    virtual void periodic() {}
};