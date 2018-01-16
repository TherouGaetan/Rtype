#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <time.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

namespace Network {
    class Logger {
    public:
        ~Logger() {};

    public:
        /**
         *	Get the unique instance of "Logger"
         */
        static Logger &getInstance();

        /**
         *	close log file.
         */
        void quit();

        /**
         *	write line, in log file and in std out.
         *
         *	@param "msg" -> is a message at write
         */
        void logLine(const std::string &pMsg);

        /**
         *	write msg, in log file and in std out.
         *
         *	@param "msg" -> print msg on the end of file
         */
        void logMsg(const std::string &pMsg);

    private:
        /**
         *	Initialize, create, or append log file.
         */
        void Init();

    private:
        Logger(const Logger &pLog);
        Logger();

    private:
        static Logger mInstance;
        std::fstream mFstream;
    };
}

#endif
