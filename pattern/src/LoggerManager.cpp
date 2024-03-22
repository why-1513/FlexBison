#include "LoggerManager.h"

std::shared_ptr<spdlog::logger> LoggerManager::patternLogger_ = nullptr;

std::shared_ptr<spdlog::logger> LoggerManager::getPatternLogger() {
    if (!patternLogger_) {
        // 创建文件输出目标
        auto patternFileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("Pattern.log");

        // 创建控制台输出目标
        auto patternConsoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

        // 创建日志记录器并将输出目标添加到记录器中
        patternLogger_ = std::make_shared<spdlog::logger>("PatternLogger", spdlog::sinks_init_list({patternFileSink, patternConsoleSink}));
        patternLogger_->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%L] %v");

    }

    return patternLogger_;
}