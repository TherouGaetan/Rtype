#ifndef Thread_IThread_h
#define Thread_IThread_h


namespace Thread {

	class IThread {
	public:
		virtual ~IThread() {}

	public:
		virtual void join()  = 0;
		virtual void kill()  = 0;
		virtual int getIdThread() const  = 0;
	};

} /* End of namespace Thread */

#endif // !Thread_IThread_h
