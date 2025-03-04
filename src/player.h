#pragma once
#include "scheduler.h"
#include "../raylib/include/raylib.h"

#define STEP 5

class Player : public Subsystem
{
private:
    float x = 0;
    float y = 0;

public:
    Player(CommandScheduler *command_scheduler) : Subsystem(command_scheduler)
    {
        command_scheduler->add_command(Command{
            new KeyTrigger<KEY_UP>::IsDownCondition(), [&y = this->y]()
            {
                y -= STEP;
            }});
            command_scheduler->add_command(Command{
            new KeyTrigger<KEY_DOWN>::IsDownCondition(), [&y = this->y]()
            {
                y += STEP;
            }});
            command_scheduler->add_command(Command{
            new KeyTrigger<KEY_RIGHT>::IsDownCondition(), [&x = this->x]()
            {
                x += STEP;
            }});
            command_scheduler->add_command(Command{
            new KeyTrigger<KEY_LEFT>::IsDownCondition(), [&x = this->x]()
            {
                x -= STEP;
            }});
    }
    ~Player() {}

    void periodic()
    {
        DrawCircle(x, y, 5, RED);
    }
};