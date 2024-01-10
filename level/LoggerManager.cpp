#include "LoggerManager.h"

std::shared_ptr<spdlog::logger> LoggerManager::levelLogger_ = nullptr;

std::shared_ptr<spdlog::logger> LoggerManager::getLevelLogger() {
    if (!levelLogger_) {
        // 创建文件输出目标
        auto levelFileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("Level.log");

        // 创建控制台输出目标
        auto levelConsoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

        // 创建日志记录器并将输出目标添加到记录器中
        levelLogger_ = std::make_shared<spdlog::logger>("LevelLogger", spdlog::sinks_init_list({levelFileSink, levelConsoleSink}));
        levelLogger_->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%L] %v");

    }

    return levelLogger_;
}