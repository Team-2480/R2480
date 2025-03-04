#include "scheduler.h"

void CommandScheduler::periodic()
{
    std::vector<std::vector<Command>::iterator> delete_queue;
    for (auto it = task_queue.begin(); it != task_queue.end(); it++)
    {
        if (it->condition->is_true())
            it->callback();
        if (it->condition->to_delete())
            delete_queue.push_back(it);
    }
    for (auto queued : delete_queue)
        task_queue.erase(queued);
    delete_queue.clear();
    for (auto system : subsystems)
        system->periodic();
}