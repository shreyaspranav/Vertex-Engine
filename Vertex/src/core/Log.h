#pragma once
#include "spdlog/spdlog.h"
#include <spdlog/sinks/stdout_color_sinks.h>

#include "Core.h"

namespace Vertex {

	class VERTEX_API Log
	{
	public:
		static void InitLoggger();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


#ifdef VT_DEBUG
	#define VT_INIT_LOGGER Vertex::Log::InitLoggger()
	
	//Core Logger
	#define VT_LOG_ENGINE_ERROR(...)   ::Vertex::Log::GetCoreLogger()->error(__VA_ARGS__)
	#define VT_LOG_ENGINE_WARN(...)    ::Vertex::Log::GetCoreLogger()->warn(__VA_ARGS__)
	#define VT_LOG_ENGINE_INFO(...)    ::Vertex::Log::GetCoreLogger()->info(__VA_ARGS__)
	#define VT_LOG_ENGINE_TRACE(...)   ::Vertex::Log::GetCoreLogger()->trace(__VA_ARGS__)
	
	// Client Logger
	#define VT_LOG_ERROR(...)		   ::Vertex::Log::GetClientLogger()->error(__VA_ARGS__)
	#define VT_LOG_WARN(...)		   ::Vertex::Log::GetClientLogger()->warn(__VA_ARGS__)
	#define VT_LOG_INFO(...)		   ::Vertex::Log::GetClientLogger()->info(__VA_ARGS__)
	#define VT_LOG_TRACE(...)		   ::Vertex::Log::GetClientLogger()->trace(__VA_ARGS__)
	#else
#define VT_INIT_LOGGER

	//Core Logger
	#define VT_LOG_ENGINE_ERROR(...) 
	#define VT_LOG_ENGINE_WARN(...)  
	#define VT_LOG_ENGINE_INFO(...)  
	#define VT_LOG_ENGINE_TRACE(...) 
	
	// Client Logger
	#define VT_LOG_ERROR(...)		 
	#define VT_LOG_WARN(...)		 
	#define VT_LOG_INFO(...)		 
	#define VT_LOG_TRACE(...)		 

#endif