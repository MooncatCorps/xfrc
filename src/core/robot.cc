#include "robot.hh"

#include <frc2/command/CommandScheduler.h>

namespace xfrc {

robot::robot() = default;

auto
robot::RobotInit() -> void { }

auto
robot::RobotPeriodic() -> void {
    frc2::CommandScheduler::GetInstance().Run();
}

auto
robot::DisabledInit() -> void { }

auto
robot::DisabledPeriodic() -> void { }

auto
robot::AutonomousInit() -> void { }

auto
robot::AutonomousPeriodic() -> void { }

auto
robot::TeleopInit() -> void { }

auto
robot::TeleopPeriodic() -> void { }

auto
robot::TestPeriodic() -> void { }

auto
robot::SimulationInit() -> void { }

auto
robot::SimulationPeriodic() -> void { }

} // namespace xfrc
