#include "profiler.hpp"
#include <iostream>

namespace Prof {

	const double CLOCK_TICKTIME = std::chrono::high_resolution_clock::period::num/double(std::chrono::high_resolution_clock::period::den);


	// ********************************************************************* //
	// ProfileStack
	// ********************************************************************* //

	void ProfileStack::push()
	{
		m_TimeStack.push(0);
	}

	Ticks ProfileStack::pop( const Ticks& functionTime )
	{
		Ticks t = m_TimeStack.top();
		m_TimeStack.pop();

		if (!m_TimeStack.empty()) {
			Ticks parent = m_TimeStack.top();
			parent += functionTime;
			m_TimeStack.pop();
			m_TimeStack.push(parent);
		}

		return t;
	}
	
	ProfileStack* ProfileStack::getInstance() {
		static ProfileStack* instance = nullptr;

		if (instance == nullptr) {
			instance = new ProfileStack();
		}

		return instance;
	}
	
	// ********************************************************************* //
	// ProfileCollector
	// ********************************************************************* //
	ProfileCollector::~ProfileCollector()
	{
		std::chrono::high_resolution_clock::now();
		std::cerr << "Consumed time in    " << m_function << "()   [" << m_file << "] :\n    ";
		std::cerr << (m_collectetedTime*CLOCK_TICKTIME*1000.0) << " ms    [";
		std::cerr << (m_collectetedTimeExclusive*CLOCK_TICKTIME*1000.0) << " ms]\n";
	}



	// ********************************************************************* //
	// ScopeProfiler
	// ********************************************************************* //
	ScopeProfiler::ScopeProfiler( ProfileCollector& collector ) :
			m_collector( collector )
	{
		m_startPoint = std::chrono::high_resolution_clock::now();
		ProfileStack::getInstance()->push();
	}

	ScopeProfiler::~ScopeProfiler()
	{
		Ticks timeSpan = (std::chrono::high_resolution_clock::now()-m_startPoint).count();
		Ticks subTime = ProfileStack::getInstance()->pop(timeSpan);
		m_collector.addTime( timeSpan, timeSpan-subTime );
	}

}