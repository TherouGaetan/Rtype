#include "Logger.hpp"

namespace Network {
    Logger Logger::mInstance = Logger();

    Logger::Logger() {
        Init();
    }

    Logger::Logger(const Logger &pLog) {
        Init();
    }


    Logger &Logger::getInstance() {
        return mInstance;
    }

    void Logger::Init() {
        std::string filename("log-");
        time_t now = time(0);
        struct tm timeinfo;
#ifdef TARGET_OS_WIN32
        localtime_s(&timeinfo, &now);
#else
        localtime_r(&now, &timeinfo);
#endif /*__linux*/
        filename.append(std::to_string(timeinfo.tm_mday)).append("-")
                .append(std::to_string(1 + timeinfo.tm_mon)).append("-")
                .append(std::to_string(1900 + timeinfo.tm_year)).append(".log");
        std::cout << "Initializing logger in " << filename << "... ";
        mFstream.open(filename, std::fstream::out | std::fstream::app);
        if (!mFstream.is_open()) {
            std::cout << "error!" << std::endl;
            std::cerr << "Error while opening file" << std::endl;
        } else
            std::cout << "done!" << std::endl;
    }

    void Logger::quit() {
        if (mFstream.is_open()) {
            std::cout << "Closing file... ";
            mFstream.close();
            if (mFstream.is_open())
                std::cout << "error!" << std::endl;
            else
                std::cout << "done!" << std::endl;
        }
    }

    void Logger::logLine(const std::string &pMsg) {
        if (mFstream.is_open()) {
            mFstream << pMsg << std::endl;
            mFstream.flush();
            std::cout << pMsg << std::endl;
        } else {
            std::cerr << "Error while loging mesage: \"" << pMsg << "\"" << std::endl;
        }
    }

    void Logger::logMsg(const std::string &pMsg) {
        if (mFstream.is_open()) {
            mFstream << pMsg;
            mFstream.flush();
            std::cout << pMsg;
        } else {
            std::cerr << "Error while loging mesage: " << pMsg << std::endl;
        }
    }
}