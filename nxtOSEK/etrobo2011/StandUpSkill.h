#ifndef STANDUPSKILL_H
#define STANDUPSKILL_H

// #include "Activator.h"
// #include "TripodActivator.h"
#include "Motor.h"

using namespace ecrobot;
class Activator;
class TripodActivator;

class StandUpSkill {
 public:
  StandUpSkill(Activator& activator,
               TripodActivator& tripodActivator,
               Motor& leftMotor,
               Motor& rightMotor,
               Motor& tailMotor)
      : mActivator(activator),
        mTripodActivator(tripodActivator),
        mLeftMotor(leftMotor),
        mRightMotor(rightMotor),
        mTailMotor(tailMotor),
        mIsStandUp(false),
        mStableCount(0),
        mOnlyFirst(true),
        mLastDiff(0.0F),
        mIterm(0.0F)
  {}
  
  ~StandUpSkill(){}

  void execute();

  bool isStandUp() const;
  
 private:

  bool isStable() const;

  void tail_control_with_PID(signed int target_angle);
  
  Activator& mActivator;
  TripodActivator& mTripodActivator;
  Motor& mLeftMotor;
  Motor& mRightMotor;
  Motor& mTailMotor;
  bool mIsStandUp;
  int mStableCount;
  bool mOnlyFirst;

  // 微分動作を計算するための、前回の誤差を保持する。
  float mLastDiff;
  // 積分動作を保持するためのフィールド。
  float mIterm;
};

#endif
