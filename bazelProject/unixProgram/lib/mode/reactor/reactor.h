#include "oshook.h"

namespace modelib
{
    class EventHandler;
    class Reactor : EventHandler
    {
        private:
            /* data */
            int remove_handler(int fd, const EventHandler & handler);
            int add_handler(int fd, const & EventHandler & handler);
        public:
            reactor(/* args */);
            ~reactor();

        int set_events(int fd);
        int set_timer(int fd);
        int remove_timer(int fd);

        
    };
}
