#include <thread>
#include "server.h"
#include "client.h"

static const int PORT = 12345;

int main()
{
    std::thread server_thread(server_main, PORT);
    std::this_thread::sleep_for( std::chrono::seconds(3));
    std::thread client_thread(client_main, PORT);

    server_thread.join();
    client_thread.join();
}
