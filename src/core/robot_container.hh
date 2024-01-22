#ifndef XFRC_CORE_ROBOT_CONTAINER_HH
#define XFRC_CORE_ROBOT_CONTAINER_HH

#include "frc/geometry/Translation2d.h"
#include "rev/SparkMaxPIDController.h"
#include "rev/SparkMaxRelativeEncoder.h"
#include "units/length.h"
#include <cstdint>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc2/command/button/CommandXboxController.h>
#include <rev/CANSparkMax.h>

using rev::CANSparkMax::ControlType::kPosition;
using rev::CANSparkMax::ControlType::kVelocity;
using rev::CANSparkMax::MotorType::kBrushless;

namespace xfrc {

class robot_container {
public:
    explicit robot_container();

    auto
    robot_init() -> uint8_t;

    auto
    robot_periodic() -> uint8_t;

    auto
    disabled_init() -> uint8_t;

    auto
    disabled_periodic() -> uint8_t;

    auto
    autonomous_init() -> uint8_t;

    auto
    autonomous_periodic() -> uint8_t;

    auto
    teleop_init() -> uint8_t;

    auto
    teleop_periodic() -> uint8_t;

    auto
    test_periodic() -> uint8_t;

    auto
    simulation_init() -> uint8_t;

    auto
    simulation_periodic() -> uint8_t;

private:
    double const PID_RT_P  = 6e-5;
    double const PID_RT_I  = 1e-6;
    double const PID_RT_D  = 0;
    double const PID_RT_IZ = 0;
    double const PID_RT_FF = 0.000015;

    double const PID_VL_P  = 6e-4;
    double const PID_VL_I  = 1e-6;
    double const PID_VL_D  = 0;
    double const PID_VL_IZ = 0;
    double const PID_VL_FF = 0.000015;

    double const PID_MAX = 1;
    double const PID_MIN = -1;

    frc2::CommandXboxController controller { 0 };

    int32_t const SDMPPTR11_ID = 11;
    int32_t const SDMWPTR12_ID = 12;

    int32_t const SDMPPTL21_ID = 21;
    int32_t const SDMWPTL22_ID = 22;

    int32_t const SDMPPBL31_ID = 31;
    int32_t const SDMWPBL32_ID = 32;

    int32_t const SDMPPBR41_ID = 41;
    int32_t const SDMWPBR42_ID = 42;

    rev::CANSparkMax sd_mp_ptr_11 { SDMPPTR11_ID, kBrushless };
    rev::CANSparkMax sd_mw_ptr_12 { SDMWPTR12_ID, kBrushless };

    rev::CANSparkMax sd_mp_ptl_21 { SDMPPTL21_ID, kBrushless };
    rev::CANSparkMax sd_mw_ptl_22 { SDMWPTL22_ID, kBrushless };

    rev::CANSparkMax sd_mp_pbl_31 { SDMPPBL31_ID, kBrushless };
    rev::CANSparkMax sd_mw_pbl_32 { SDMWPBL32_ID, kBrushless };

    rev::CANSparkMax sd_mp_pbr_41 { SDMPPBR41_ID, kBrushless };
    rev::CANSparkMax sd_mw_pbr_42 { SDMWPBR42_ID, kBrushless };

    rev::SparkMaxRelativeEncoder sd_mp_ptr_enc_11 = sd_mp_ptr_11.GetEncoder();
    rev::SparkMaxRelativeEncoder sd_mw_ptr_enc_12 = sd_mw_ptr_12.GetEncoder();

    rev::SparkMaxRelativeEncoder sd_mp_ptl_enc_21 = sd_mp_ptl_21.GetEncoder();
    rev::SparkMaxRelativeEncoder sd_mw_ptl_enc_22 = sd_mw_ptl_22.GetEncoder();

    rev::SparkMaxRelativeEncoder sd_mp_pbl_enc_31 = sd_mp_pbl_31.GetEncoder();
    rev::SparkMaxRelativeEncoder sd_mw_pbl_enc_32 = sd_mw_pbl_32.GetEncoder();

    rev::SparkMaxRelativeEncoder sd_mp_pbr_enc_41 = sd_mp_pbr_41.GetEncoder();
    rev::SparkMaxRelativeEncoder sd_mw_pbr_enc_42 = sd_mw_pbr_42.GetEncoder();

    rev::SparkMaxPIDController sd_mp_ptr_pid_11 =
        sd_mp_ptr_11.GetPIDController();
    rev::SparkMaxPIDController sd_mw_ptr_pid_12 =
        sd_mw_ptr_12.GetPIDController();

    rev::SparkMaxPIDController sd_mp_ptl_pid_21 =
        sd_mp_ptl_21.GetPIDController();
    rev::SparkMaxPIDController sd_mw_ptl_pid_22 =
        sd_mw_ptl_22.GetPIDController();

    rev::SparkMaxPIDController sd_mp_pbl_pid_31 =
        sd_mp_pbl_31.GetPIDController();
    rev::SparkMaxPIDController sd_mw_pbl_pid_32 =
        sd_mw_pbl_32.GetPIDController();

    rev::SparkMaxPIDController sd_mp_pbr_pid_41 =
        sd_mp_pbr_41.GetPIDController();
    rev::SparkMaxPIDController sd_mw_pbr_pid_42 =
        sd_mw_pbr_42.GetPIDController();

    units::centimeter_t const DIAGONAL_DISTANCE_TO_ROBOT_CENTER = 36.5_cm;
    units::meters_per_second_t const  linear_velocity           = 1_mps;
    units::radians_per_second_t const angular_velocity          = 15_deg_per_s;
    double const                      RTD                       = 360.0;

    frc::Translation2d top_right_module_location {
        DIAGONAL_DISTANCE_TO_ROBOT_CENTER,
        DIAGONAL_DISTANCE_TO_ROBOT_CENTER
    };

    frc::Translation2d top_left_module_location {
        -DIAGONAL_DISTANCE_TO_ROBOT_CENTER,
        DIAGONAL_DISTANCE_TO_ROBOT_CENTER
    };

    frc::Translation2d bottom_left_module_location {
        -DIAGONAL_DISTANCE_TO_ROBOT_CENTER,
        -DIAGONAL_DISTANCE_TO_ROBOT_CENTER
    };

    frc::Translation2d bottom_right_module_location {
        DIAGONAL_DISTANCE_TO_ROBOT_CENTER,
        -DIAGONAL_DISTANCE_TO_ROBOT_CENTER
    };

    frc::SwerveDriveKinematics<4> kinematics { top_right_module_location,
                                               top_left_module_location,
                                               bottom_left_module_location,
                                               bottom_right_module_location };
};

} // namespace xfrc

#endif
