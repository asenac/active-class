#include "ActiveClass.hpp"

ActiveClass::ActiveClass() :
    m_work(m_io_service)
{
}

ActiveClass::~ActiveClass()
{
    // Ensures stop
    stop();
}

void ActiveClass::start()
{
    // Move constructor
    m_thread = boost::thread(
            boost::bind(&boost::asio::io_service::run, &m_io_service));
}

void ActiveClass::stop()
{
    m_io_service.stop();
    m_thread.join();
}

void ActiveClass::wait()
{
    m_thread.join();
}

