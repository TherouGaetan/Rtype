#pragma once

#include <string>

namespace Network {
	namespace TSocket {
		class Packet {
		public:
			Packet();
			~Packet();

		public:
			Packet operator<<(const std::string &pMsg);

		public:
			Packet append(const std::string &pAppend);
			const std::string &getBuff() const;
			void str(const std::string &pMsg);
			const std::string &str();
			void erase();
			void clear();

		private:
			std::string mData;
		};
	}
}
