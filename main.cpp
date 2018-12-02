#include <iostream>

#include <spdlog/spdlog.h>
#include <CMakeVariables.hpp>
#include <Map.hpp>
#include <Algorithm.hpp>
#include <StandardBruteForce.hpp>
#include <OptimalMTBruteForce.hpp>
#include <BranchAndBoundMTBruteForce.hpp>

int main()
{
    auto sink   = std::make_shared<spdlog::sinks::simple_file_sink_mt>(
        CMAKE_CURRENT_SOURCE_DIR + "/logs/run.log");
    auto logger = std::make_shared<spdlog::logger>("main", sink);
    spdlog::register_logger(logger);

    spdlog::get("main")->set_level(spdlog::level::info);
    spdlog::get("main")->flush_on(spdlog::level::info);
    spdlog::get("main")->info("Initialisation done.");

    Map map_4("/own4.city");
    Map map_5("/own5.city");
    Map map_6("/own6.city");
    Map map_7("/own7.city");
    Map map_8("/own8.city");
    Map map_9("/own9.city");
    Map map_10("/own10.city");


    auto start = std::chrono::steady_clock::now();

    std::unique_ptr<Algorithm> sbf = std::make_unique<StandardBruteForce>(map_4);
    sbf->start();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - start);
    spdlog::get("main")->info("Duration : {} microseconds", duration.count());
    std::cerr << "RESULT : " << duration.count() << std::endl;

    start = std::chrono::steady_clock::now();

    sbf = std::make_unique<StandardBruteForce>(map_5);
    sbf->start();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - start);
    spdlog::get("main")->info("Duration : {} microseconds", duration.count());
    std::cerr << "RESULT : " << duration.count() << std::endl;

    start = std::chrono::steady_clock::now();

    sbf = std::make_unique<StandardBruteForce>(map_6);
    sbf->start();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - start);
    spdlog::get("main")->info("Duration : {} microseconds", duration.count());
    std::cerr << "RESULT : " << duration.count() << std::endl;

    start = std::chrono::steady_clock::now();

    sbf = std::make_unique<StandardBruteForce>(map_7);
    sbf->start();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - start);
    spdlog::get("main")->info("Duration : {} microseconds", duration.count());
    std::cerr << "RESULT : " << duration.count() << std::endl;

    start = std::chrono::steady_clock::now();

    sbf = std::make_unique<StandardBruteForce>(map_8);
    sbf->start();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - start);
    spdlog::get("main")->info("Duration : {} microseconds", duration.count());
    std::cerr << "RESULT : " << duration.count() << std::endl;

    start = std::chrono::steady_clock::now();

    sbf = std::make_unique<StandardBruteForce>(map_9);
    sbf->start();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - start);
    spdlog::get("main")->info("Duration : {} microseconds", duration.count());
    std::cerr << "RESULT : " << duration.count() << std::endl;

    start = std::chrono::steady_clock::now();

    sbf = std::make_unique<StandardBruteForce>(map_10);
    sbf->start();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - start);
    spdlog::get("main")->info("Duration : {} microseconds", duration.count());
    std::cerr << "RESULT : " << duration.count() << std::endl;



    spdlog::get("main")->info("");
    spdlog::get("main")->info("NEW");
    spdlog::get("main")->info("");
    std::cerr << "RESULT : " << std::endl;
    std::cerr << "RESULT : " << std::endl;
    std::cerr << "RESULT : " << std::endl;


    std::unique_ptr<Algorithm> babmtbf = std::make_unique<OptimalMTBruteForce>(map_4);

    start = std::chrono::steady_clock::now();

    babmtbf = std::make_unique<OptimalMTBruteForce>(map_4);
    babmtbf->start();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - start);
    spdlog::get("main")->info("Duration : {} microseconds", duration.count());
    std::cerr << "RESULT : " << duration.count() << std::endl;

    start = std::chrono::steady_clock::now();

    babmtbf = std::make_unique<StandardBruteForce>(map_5);
    babmtbf->start();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - start);
    spdlog::get("main")->info("Duration : {} microseconds", duration.count());
    std::cerr << "RESULT : " << duration.count() << std::endl;

    start = std::chrono::steady_clock::now();

    babmtbf = std::make_unique<StandardBruteForce>(map_6);
    babmtbf->start();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - start);
    spdlog::get("main")->info("Duration : {} microseconds", duration.count());
    std::cerr << "RESULT : " << duration.count() << std::endl;

    start = std::chrono::steady_clock::now();

    babmtbf = std::make_unique<StandardBruteForce>(map_7);
    babmtbf->start();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - start);
    spdlog::get("main")->info("Duration : {} microseconds", duration.count());
    std::cerr << "RESULT : " << duration.count() << std::endl;

    start = std::chrono::steady_clock::now();

    babmtbf = std::make_unique<StandardBruteForce>(map_8);
    babmtbf->start();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - start);
    spdlog::get("main")->info("Duration : {} microseconds", duration.count());
    std::cerr << "RESULT : " << duration.count() << std::endl;

    start = std::chrono::steady_clock::now();

    babmtbf = std::make_unique<StandardBruteForce>(map_9);
    babmtbf->start();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - start);
    spdlog::get("main")->info("Duration : {} microseconds", duration.count());
    std::cerr << "RESULT : " << duration.count() << std::endl;

    start = std::chrono::steady_clock::now();

    babmtbf = std::make_unique<StandardBruteForce>(map_10);
    babmtbf->start();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - start);
    spdlog::get("main")->info("Duration : {} microseconds", duration.count());
    std::cerr << "RESULT : " << duration.count() << std::endl;

    // std::unique_ptr<Algorithm> sbf   = std::make_unique<StandardBruteForce>( map );
    // std::unique_ptr<Algorithm> omtbf = std::make_unique<OptimalMTBruteForce>( map );
    // std::unique_ptr<Algorithm> babmtbf = std::make_unique<BranchAndBoundMTBruteForce>( map );

    //	sbf->start();
    // 	omtbf->start();
    // 	babmtbf->start();

    spdlog::get("main")->info("Run Finished!");

    return EXIT_SUCCESS;
}
