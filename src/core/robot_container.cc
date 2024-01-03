#include "robot_container.hh"

#include "frc/kinematics/ChassisSpeeds.h"
#include "frc/smartdashboard/SmartDashboard.h"

namespace xfrc {

robot_container::robot_container() { }

auto
robot_container::robot_init() -> uint8_t {
    sd_mp_ptr_pid_11.SetP(PID_RT_P);
    sd_mw_ptr_pid_12.SetP(PID_VL_P);
    sd_mp_ptl_pid_21.SetP(PID_RT_P);
    sd_mw_ptl_pid_22.SetP(PID_VL_P);
    sd_mp_pbl_pid_31.SetP(PID_RT_P);
    sd_mw_pbl_pid_32.SetP(PID_VL_P);
    sd_mp_pbr_pid_41.SetP(PID_RT_P);
    sd_mw_pbr_pid_42.SetP(PID_VL_P);

    sd_mp_ptr_pid_11.SetI(PID_RT_I);
    sd_mw_ptr_pid_12.SetI(PID_VL_I);
    sd_mp_ptl_pid_21.SetI(PID_RT_I);
    sd_mw_ptl_pid_22.SetI(PID_VL_I);
    sd_mp_pbl_pid_31.SetI(PID_RT_I);
    sd_mw_pbl_pid_32.SetI(PID_VL_I);
    sd_mp_pbr_pid_41.SetI(PID_RT_I);
    sd_mw_pbr_pid_42.SetI(PID_VL_I);

    sd_mp_ptr_pid_11.SetD(PID_RT_D);
    sd_mw_ptr_pid_12.SetD(PID_VL_D);
    sd_mp_ptl_pid_21.SetD(PID_RT_D);
    sd_mw_ptl_pid_22.SetD(PID_VL_D);
    sd_mp_pbl_pid_31.SetD(PID_RT_D);
    sd_mw_pbl_pid_32.SetD(PID_VL_D);
    sd_mp_pbr_pid_41.SetD(PID_RT_D);
    sd_mw_pbr_pid_42.SetD(PID_VL_D);

    sd_mp_ptr_pid_11.SetIZone(PID_RT_IZ);
    sd_mw_ptr_pid_12.SetIZone(PID_VL_IZ);
    sd_mp_ptl_pid_21.SetIZone(PID_RT_IZ);
    sd_mw_ptl_pid_22.SetIZone(PID_VL_IZ);
    sd_mp_pbl_pid_31.SetIZone(PID_RT_IZ);
    sd_mw_pbl_pid_32.SetIZone(PID_VL_IZ);
    sd_mp_pbr_pid_41.SetIZone(PID_RT_IZ);
    sd_mw_pbr_pid_42.SetIZone(PID_VL_IZ);

    sd_mp_ptr_pid_11.SetFF(PID_RT_FF);
    sd_mw_ptr_pid_12.SetFF(PID_VL_FF);
    sd_mp_ptl_pid_21.SetFF(PID_RT_FF);
    sd_mw_ptl_pid_22.SetFF(PID_VL_FF);
    sd_mp_pbl_pid_31.SetFF(PID_RT_FF);
    sd_mw_pbl_pid_32.SetFF(PID_VL_FF);
    sd_mp_pbr_pid_41.SetFF(PID_RT_FF);
    sd_mw_pbr_pid_42.SetFF(PID_VL_FF);

    sd_mp_ptr_pid_11.SetOutputRange(PID_MIN, PID_MAX);
    sd_mw_ptr_pid_12.SetOutputRange(PID_MIN, PID_MAX);
    sd_mp_ptl_pid_21.SetOutputRange(PID_MIN, PID_MAX);
    sd_mw_ptl_pid_22.SetOutputRange(PID_MIN, PID_MAX);
    sd_mp_pbl_pid_31.SetOutputRange(PID_MIN, PID_MAX);
    sd_mw_pbl_pid_32.SetOutputRange(PID_MIN, PID_MAX);
    sd_mp_pbr_pid_41.SetOutputRange(PID_MIN, PID_MAX);
    sd_mw_pbr_pid_42.SetOutputRange(PID_MIN, PID_MAX);

    return 0;
}

auto
robot_container::robot_periodic() -> uint8_t {
    return 0;
}

auto
robot_container::disabled_init() -> uint8_t {
    return 0;
}

auto
robot_container::disabled_periodic() -> uint8_t {
    return 0;
}

auto
robot_container::autonomous_init() -> uint8_t {
    return 0;
}

auto
robot_container::autonomous_periodic() -> uint8_t {
    return 0;
}

auto
robot_container::teleop_init() -> uint8_t {
    sd_mp_ptr_enc_11.SetPosition(0);
    sd_mw_ptr_enc_12.SetPosition(0);
    sd_mp_ptl_enc_21.SetPosition(0);
    sd_mw_ptl_enc_22.SetPosition(0);
    sd_mp_pbl_enc_31.SetPosition(0);
    sd_mw_pbl_enc_32.SetPosition(0);
    sd_mp_pbr_enc_41.SetPosition(0);
    sd_mw_pbr_enc_42.SetPosition(0);

    sd_mp_ptr_11.Set(0);
    sd_mw_ptr_12.Set(0);
    sd_mp_ptl_21.Set(0);
    sd_mw_ptl_22.Set(0);
    sd_mp_pbl_31.Set(0);
    sd_mw_pbl_32.Set(0);
    sd_mp_pbr_41.Set(0);
    sd_mw_pbr_42.Set(0);

    return 0;
}

auto
robot_container::teleop_periodic() -> uint8_t {
    frc::SmartDashboard::PutNumber("sd_mp_ptr_11 %", sd_mp_ptr_11.Get());
    frc::SmartDashboard::PutNumber("sd_mw_ptr_12 %", sd_mw_ptr_12.Get());

    frc::SmartDashboard::PutNumber("sd_mp_ptr_21 %", sd_mp_ptl_21.Get());
    frc::SmartDashboard::PutNumber("sd_mw_ptr_22 %", sd_mw_ptl_22.Get());

    frc::SmartDashboard::PutNumber("sd_mp_ptr_31 %", sd_mp_pbl_31.Get());
    frc::SmartDashboard::PutNumber("sd_mw_ptr_32 %", sd_mw_pbl_32.Get());

    frc::SmartDashboard::PutNumber("sd_mp_ptr_41 %", sd_mp_pbr_41.Get());
    frc::SmartDashboard::PutNumber("sd_mw_ptr_42 %", sd_mw_pbr_42.Get());

    frc::SmartDashboard::PutNumber("sd_mp_ptr_11 angle",
                                   sd_mp_ptr_enc_11.GetPosition());
    frc::SmartDashboard::PutNumber("sd_mw_ptr_12 velocity",
                                   sd_mw_ptr_enc_12.GetVelocity());

    frc::SmartDashboard::PutNumber("sd_mp_ptr_21 angle",
                                   sd_mp_ptl_enc_21.GetPosition());
    frc::SmartDashboard::PutNumber("sd_mw_ptr_22 velocity",
                                   sd_mw_ptl_enc_22.GetVelocity());

    frc::SmartDashboard::PutNumber("sd_mp_ptr_31 angle",
                                   sd_mp_pbl_enc_31.GetPosition());
    frc::SmartDashboard::PutNumber("sd_mw_ptr_32 velocity",
                                   sd_mw_pbl_enc_32.GetVelocity());

    frc::SmartDashboard::PutNumber("sd_mp_ptr_pid_41 angle",
                                   sd_mp_pbr_enc_41.GetPosition());
    frc::SmartDashboard::PutNumber("sd_mw_ptr_pid_42 velocity",
                                   sd_mw_pbr_enc_42.GetVelocity());

    /*
    double const input_x = 0.0; // controller.GetLeftX();
    double const input_y = 0.0; // controller.GetLeftY();
    double const input_r = 0.0; // controller.GetRightX();

    frc::ChassisSpeeds speed = { linear_velocity * input_x + 3_mps,
                                 linear_velocity * input_y,
                                 angular_velocity * input_r };

    auto const [tr, tl, bl, br] = kinematics.ToSwerveModuleStates(speed);

    sd_mp_ptr_pid_11.SetReference(tr.angle.Degrees().value() / RTD, kPosition);
    sd_mw_ptr_pid_12.SetReference(tr.speed.value(), kVelocity);

    sd_mp_ptl_pid_21.SetReference(tl.angle.Degrees().value() / RTD, kPosition);
    sd_mw_ptl_pid_22.SetReference(tl.speed.value(), kVelocity);

    sd_mp_pbl_pid_31.SetReference(bl.angle.Degrees().value() / RTD, kPosition);
    sd_mw_pbl_pid_32.SetReference(bl.speed.value(), kVelocity);

    sd_mp_pbr_pid_41.SetReference(br.angle.Degrees().value() / RTD, kPosition);
    sd_mw_pbr_pid_42.SetReference(br.speed.value(), kVelocity);
    */

    sd_mw_ptr_12.Set(0.1);
    sd_mw_ptl_22.Set(0.1);
    sd_mw_pbl_32.Set(0.1);
    sd_mw_pbr_42.Set(0.1);

    return 0;
}

auto
robot_container::test_periodic() -> uint8_t {
    return 0;
}

auto
robot_container::simulation_init() -> uint8_t {
    return 0;
}

auto
robot_container::simulation_periodic() -> uint8_t {
    return 0;
}

} // namespace xfrc
