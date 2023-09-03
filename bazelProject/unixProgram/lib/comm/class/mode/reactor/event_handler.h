
namespace modelib
{

    class EventHandler()
    {
        private:
            EventHandler() = default;
            ~EventHandler() = default;
        public:
            int handle_read();
            int handle_write();
            int handle_timeout();
    };

}