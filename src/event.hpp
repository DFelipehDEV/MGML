#ifndef EVENT_HPP
#define EVENT_HPP
#include <string>
namespace MGML {
    class Event {
        public:
            Event(const std::string& functionName, const std::string& define);
            ~Event() = default;

            std::string GetDefine();
            void SetDefine(const std::string& define);
            std::string GetFunctionName();
            void SetFunctionName(const std::string& name);
        private:
            std::string m_define;
            std::string m_functionName;

    };
    enum Events {
        BEGIN_STEP = 0,
        STEP,
        END_STEP,
        DRAW,
        DESTROY,
        ALARM_0,
        ALARM_1,
        ALARM_2,
        ALARM_3,
        ALARM_4,
        ALARM_5,
        ALARM_6,
        ALARM_7,
        ALARM_8,
        ALARM_9,
        ALARM_10,
        ALARM_11,
        OUTSIDE_ROOM,
        INTERSECT_BOUNDARY,
        GAME_START,
        GAME_END,
        ROOM_START,
        ROOM_END,
        //NO_LIVES,
        ANIMATION_END,
        PATH_END,
        //NO_HEALTH,
        USER_0,
        USER_1,
        USER_2,
        USER_3,
        USER_4,
        USER_5,
        USER_6,
        USER_7,
        USER_8,
        USER_9,
        USER_10,
        USER_11,
        USER_12,
        USER_13,
        USER_14,
        USER_15,
        GAME_CLOSE,
        OUTSIDE_VIEW_0,
        OUTSIDE_VIEW_1,
        OUTSIDE_VIEW_2,
        OUTSIDE_VIEW_3,
        OUTSIDE_VIEW_4,
        OUTSIDE_VIEW_5,
        OUTSIDE_VIEW_6,
        OUTSIDE_VIEW_7,
        BOUNDARY_VIEW_0,
        BOUNDARY_VIEW_1,
        BOUNDARY_VIEW_2,
        BOUNDARY_VIEW_3,
        BOUNDARY_VIEW_4,
        BOUNDARY_VIEW_5,
        BOUNDARY_VIEW_6,
        BOUNDARY_VIEW_7,
        SIZE,
    };
}
#endif // EVENT_HPP