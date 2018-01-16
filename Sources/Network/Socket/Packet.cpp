#include "Packet.hpp"

namespace Network {
	namespace TSocket {
		Packet::Packet() {
			mData = "";
		}

		Packet::~Packet() {
		}

		Packet Packet::operator<<(const std::string &pMsg) {
			mData += pMsg;
			return *this;
		}

		Packet Packet::append(const std::string &pAppend) {
			mData += pAppend;
			return *this;
		}

		const std::string &Packet::getBuff() const {
			return mData;
		}

		void Packet::str(const std::string &pMsg) {
			mData += pMsg;
		}

		const std::string &Packet::str() {
			return mData;
		}

		void Packet::erase() {
			this->mData.erase();
		}

		void Packet::clear() {
			mData = "";
		}
	}
}