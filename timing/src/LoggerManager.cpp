#include "LoggerManager.h"

std::shared_ptr<spdlog::logger> LoggerManager::timingLogger_ = nullptr;

std::shared_ptr<spdlog::logger> LoggerManager::getTimingLogger() {
    if (!timingLogger_) {
        // 创建文件输出目标
        auto timingFileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("Timing.log");

        // 创建控制台输出目标
        auto timingConsoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

        // 创建日志记录器并将输出目标添加到记录器中
        timingLogger_ = std::make_shared<spdlog::logger>("TimingLogger", spdlog::sinks_init_list({timingFileSink, timingConsoleSink}));
        timingLogger_->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%L] %v");

    }

    return timingLogger_;
}