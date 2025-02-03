#include "logging.hpp"
#include <quill/Backend.h>
#include <quill/Frontend.h>
#include <quill/sinks/ConsoleSink.h>

quill::Logger* g_mainLog;
std::shared_ptr<quill::Sink> g_Sink;



int main(int argc, char* argv[]) try {
	quill::Backend::start();
	g_Sink = quill::Frontend::create_or_get_sink<quill::ConsoleSink>("console1");
	g_Sink->set_log_level_filter(quill::LogLevel::Debug);
	g_mainLog = rgn::get_or_create("main");

	quill::Backend::stop();
	return 0;
} catch (const std::exception& e) {
	LOG_CRITICAL(g_mainLog, "{}", e.what());
	quill::Backend::stop();
}

namespace rgn {

quill::Logger* get_or_create(const char* name) { return quill::Frontend::create_or_get_logger(name, g_Sink); }

} // namespace ksn