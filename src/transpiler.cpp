#include "transpiler.hpp"
#include <regex>
#include "log.hpp"
#include <sstream>
#include <chrono>
namespace MGML {
    Event* Transpiler::event[Events::SIZE] = { nullptr };
    Transpiler::Transpiler() {
        if (Transpiler::event[Events::SIZE] == nullptr) {
            InitializeEvent();
        }
    }

    Transpiler::~Transpiler() {
        //m_file->close();
    }

    void Transpiler::Execute(std::string inputPath, std::string outputPath) {
        auto startTime = std::chrono::high_resolution_clock::now(); 
        std::ifstream inputFile(inputPath);
        std::ofstream outputFile(outputPath);
        if (!inputFile.good()) {
            Log::PrintLine("Unable to open input " + inputPath, LogType::ERROR);
            return;
        }

        if (!outputFile.good()) {
            Log::PrintLine("Unable to open output " + outputPath, LogType::ERROR);
            return;
        }

        std::regex actions[Events::SIZE];
        for (int i = 0; i < Events::SIZE; i++) {
            actions[i] = std::basic_regex("\\bfunction " + event[i]->GetFunctionName() + "\\(\\)");
        }
        std::basic_regex comment("\\/\\/.*|\\/\\*.*?\\*\\/");
        std::basic_regex increment("([a-zA-Z_][a-zA-Z0-9_]*)\\+\\+|\\+\\+([a-zA-Z_][a-zA-Z0-9_]*)");
        std::basic_regex decrement("([a-zA-Z_][a-zA-Z0-9_]*)\\-\\-|\\-\\-([a-zA-Z_][a-zA-Z0-9_]*)");
        std::basic_regex trueTo1("true");
        std::basic_regex falseTo0("false");
        //std::regex types("\\b(function)\\b");

        std::stringstream buffer;
        outputFile << "#define Create_0\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/";
        buffer << inputFile.rdbuf();
        std::string modifiedBuffer = buffer.str();

        
        modifiedBuffer = std::regex_replace(modifiedBuffer, comment, "");
        modifiedBuffer = std::regex_replace(modifiedBuffer, increment, "$1+=1");
        modifiedBuffer = std::regex_replace(modifiedBuffer, decrement, "$1-=1");

        for (int i = 0; i < Events::SIZE; i++) {
            modifiedBuffer = std::regex_replace(modifiedBuffer, actions[i], event[i]->GetDefine());
        }

        outputFile << modifiedBuffer;

        outputFile.close();
        inputFile.close();
        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

        Log::PrintLine(inputPath + " took " + std::to_string(duration.count()) + "ms");
    }
    
    void Transpiler::InitializeEvent() {
        event[Events::BEGIN_STEP] = new Event("on_begin_step", "\n#define Step_1\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::STEP] = new Event("on_step", "\n#define Step_0\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::END_STEP] = new Event("on_end_step", "\n#define Step_2\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::DRAW] = new Event("on_draw", "\n#define Draw_0\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::DESTROY] = new Event("on_destroy", "\n#define Destroy_0\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::ALARM_0] = new Event("on_alarm_0", "\n#define Alarm_0\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::ALARM_1] = new Event("on_alarm_1", "\n#define Alarm_1\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::ALARM_2] = new Event("on_alarm_2", "\n#define Alarm_2\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::ALARM_3] = new Event("on_alarm_3", "\n#define Alarm_3\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::ALARM_4] = new Event("on_alarm_4", "\n#define Alarm_4\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::ALARM_5] = new Event("on_alarm_5", "\n#define Alarm_5\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::ALARM_6] = new Event("on_alarm_6", "\n#define Alarm_6\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::ALARM_7] = new Event("on_alarm_7", "\n#define Alarm_7\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::ALARM_8] = new Event("on_alarm_8", "\n#define Alarm_8\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");    
        event[Events::ALARM_9] = new Event("on_alarm_10", "\n#define Alarm_10\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::ALARM_10] = new Event("on_alarm_10", "\n#define Alarm_10\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::ALARM_11] = new Event("on_alarm_11", "\n#define Alarm_11\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::OUTSIDE_ROOM] = new Event("on_outside_room", "\n#define Other_0\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::INTERSECT_BOUNDARY] = new Event("on_intersect_boundary", "\n#define Other_1\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::GAME_START] = new Event("on_game_start", "\n#define Other_2\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::GAME_END] = new Event("on_game_end", "\n#define Other_3\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::ROOM_START] = new Event("on_room_start", "\n#define Other_4\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::ROOM_END] = new Event("on_game_end", "\n#define Other_5\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::NO_LIVES] = new Event("on_no_lives", "\n#define Other_6\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::ANIMATION_END] = new Event("on_animation_end", "\n#define Other_7\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::PATH_END] = new Event("on_path_end", "\n#define Other_8\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::NO_HEALTH] = new Event("on_no_health", "\n#define Other_9\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::USER_0] = new Event("on_user_0", "\n#define Other_10\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::USER_1] = new Event("on_user_1", "\n#define Other_11\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::USER_2] = new Event("on_user_2", "\n#define Other_12\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::USER_3] = new Event("on_user_3", "\n#define Other_13\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::USER_4] = new Event("on_user_4", "\n#define Other_14\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::USER_5] = new Event("on_user_5", "\n#define Other_15\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::USER_6] = new Event("on_user_6", "\n#define Other_16\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::USER_7] = new Event("on_user_7", "\n#define Other_17\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::USER_8] = new Event("on_user_8", "\n#define Other_18\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::USER_9] = new Event("on_user_9", "\n#define Other_19\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::USER_10] = new Event("on_user_10", "\n#define Other_20\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::USER_11] = new Event("on_user_11", "\n#define Other_21\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::USER_12] = new Event("on_user_12", "\n#define Other_22\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::USER_13] = new Event("on_user_13", "\n#define Other_23\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::USER_14] = new Event("on_user_14", "\n#define Other_24\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::USER_15] = new Event("on_user_15", "\n#define Other_25\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::GAME_CLOSE] = new Event("on_game_close", "\n#define Other_30\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::OUTSIDE_VIEW_0] = new Event("on_outside_view_0", "\n#define Other_40\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::OUTSIDE_VIEW_1] = new Event("on_outside_view_1", "\n#define Other_41\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::OUTSIDE_VIEW_2] = new Event("on_outside_view_2", "\n#define Other_42\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::OUTSIDE_VIEW_3] = new Event("on_outside_view_3", "\n#define Other_43\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::OUTSIDE_VIEW_4] = new Event("on_outside_view_4", "\n#define Other_44\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::OUTSIDE_VIEW_5] = new Event("on_outside_view_5", "\n#define Other_45\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::OUTSIDE_VIEW_6] = new Event("on_outside_view_6", "\n#define Other_46\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::OUTSIDE_VIEW_7] = new Event("on_outside_view_7", "\n#define Other_47\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::BOUNDARY_VIEW_0] = new Event("on_boundary_view_0", "\n#define Other_50\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::BOUNDARY_VIEW_1] = new Event("on_boundary_view_1", "\n#define Other_51\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::BOUNDARY_VIEW_2] = new Event("on_boundary_view_2", "\n#define Other_52\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::BOUNDARY_VIEW_3] = new Event("on_boundary_view_3", "\n#define Other_53\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::BOUNDARY_VIEW_4] = new Event("on_boundary_view_4", "\n#define Other_54\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::BOUNDARY_VIEW_5] = new Event("on_boundary_view_5", "\n#define Other_55\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::BOUNDARY_VIEW_6] = new Event("on_boundary_view_6", "\n#define Other_56\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
        event[Events::BOUNDARY_VIEW_7] = new Event("on_boundary_view_7", "\n#define Other_57\n/*\"/*'/**//* YYD ACTION\nlib_id=1\naction_id=603\napplies_to=self\n*/");
    }
    Event* Transpiler::GetEvent() const {
        return *event;
    }
}