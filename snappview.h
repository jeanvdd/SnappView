//
//  snappview.h
//  Snappview
//
//  Created by Xavier de Ryckel on 28/11/12.
//  Copyright (c) 2012-2013 Xavier de Ryckel. All rights reserved.
//
#import <UIKit/UIKit.h>

@interface snappview : NSObject

/////////////////////////////
// SNAPPVIEW BETA 1.0.0    //
// For iOS 5.0 and beyond  //
// Supporting ARC projects //
/////////////////////////////

////////////////////////////////////////////////////////////////////
// OpenGL & AvFoundation support :                                //
//   Screenshots not available for OpenGL or AvFoundation views   //
//   (will result in a black area for that precise part of view)  //
////////////////////////////////////////////////////////////////////

//ONLY MANDATORY LINE TO PUT IN YOUR APP DELEGATE'S FUNCTION didFinishLaunchingWithOptions:
//
// [[snappview sharedInstance] startWithAppKey:@"YOURKEY" trigger:@"shake"];
//
//Also add #import "snappview.h"  in your appdelegate file
//
//
//DON'T FORGET TO:
// - add the required frameworks to the project (Foundation, Coregraphics, UIKit, CoreData, MobileCoreServices, SystemConfiguration)
//      in buildphases/ link binary with libraries
// - add libz.dylib in buildphases/
// - add the files.a (link binary with libraries) .h and .bundle (buildphases/copy bundle resources) to your project
// - change YOURKEY with your own key provided by snappview.comc


////////////////////////////////////////////////////////////////////////////////
//DESCRIPTION:      MAIN METHOD
//USAGE:            *MANDATORY*
//EXAMPLE:          [[snappview sharedInstance] startWithAppKey:@"YOURKEY" trigger:@"shake"];
//                      where YOURKEY looks like u0p0.0000000000000.0000000
//                      and can be found in your dashboard on snappview.com
//                  You can replace @"shake" by @"none" if you prefer to trigger snappview manually
//                      anywhere in your code rather than being triggered by shakes
//                  You can therefore define your own movement by chosing the trigger @"none"
//                      and by calling  [[snappview sharedInstance] triggerSnappview]; whenever
//                      your own code recognizes the move you implemented
//                  the startWithAppKey code HAS to be set
//                      inside your main delegate function didFinishLaunchingWithOptions
//                      - (BOOL)application:(UIApplication *)application
//                      didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
//                  Note that the shake gesture will be recognized only on a REAL DEVICE,
//                      not in Apple's SIMULATOR (the simulator doesn't simulate the accelerometer
//                      even if the shake gesture is provided but you can call snappview
//                      with [[snappview sharedInstance] triggerSnappview]; after calling
//                      [[snappview sharedInstance] startWithAppKey:@"YOURKEY" trigger:@"none"];
//                      But Snappview works just fine in the simulator by calling [[snappview sharedInstance] triggerSnappview];
//                      anytime after calling this function.
//
// 
//IN-APP EFFECT:    Will display the Snappview menu when the corresponding trigger is recognized during the usage of the app
//EFFECT:           If the trigger is set to "shake", the shared accelerometer delegate will be automatically set to a snappview delegate
//                      which mean startWithAppKey will automatically execute this line of code:
//                      [UIAccelerometer sharedAccelerometer].delegate = [[snappview sharedInstance] getSnappviewUIAccelerometerDelegate];
- (void) startWithAppKey: (NSString *) key trigger:(NSString *) trigger;



////////////////////////////////////////////////////////////////////////////////
//DESCRIPTION :     MANUALLY INSTANTLY TRIGGER SNAPPVIEW MENU ANYWHERE IN YOUR CODE
//USAGE:            Facultative
//                      (to encourage your users to send your more feedback after strategic points)
//EXAMPLE:          [[snappview sharedInstance] triggerSnappview];
//IN-APP EFFECT:    Will instantly display the Snappview menu
- (void) triggerSnappview;



////////////////////////////////////////////////////////////////////////////////
//DESCRIPTION:      Check wether it's possible to display the snappview main menu with the current trigger
//USAGE:            Facultative
//                      (ex:by shaking the phone or by calling [[snappview sharedInstance] triggerSnappview])
//EXAMPLE:          BOOL b = [[snappview sharedInstance] isShakeTriggerable];
- (bool) isTriggerable;



////////////////////////////////////////////////////////////////////////////////
//DESCRIPTION:      Enable or disable the possibility to display the snappview main menu by the current trigger
//                  If you set this to true but that the shake function still don't work,
//                  you should execute the following line of code too:
//                  [UIAccelerometer sharedAccelerometer].delegate = [[snappview sharedInstance] getSnappviewUIAccelerometerDelegate];
//USAGE:            Facultative
//                      (ex:by shaking the phone or by calling [[snappview sharedInstance] triggerSnappview])
//EXAMPLE:          [[snappview sharedInstance] setShakeTriggerable:TRUE];
//DEFAULT VALUE:    TRUE
- (void) setTriggerable:(bool) trig;



////////////////////////////////////////////////////////////////////////////////
//DESCRIPTION:      This is useful if you changed the shared UIAccelerometerDelegate
//                  And that Snappview can't be triggered anymore.
//                  This function returns the instance delegate that has to be used as a UIAcceleromter delegate
//                  for Snappview in order to recognize shake movements.
//                  Call this method if you changed the UIAccelerometer delegate 
//                  so that you can restore Snappview with the following line:
//                  [UIAccelerometer sharedAccelerometer].delegate = [[snappview sharedInstance] getSnappviewUIAccelerometerDelegate];
//USAGE:            Facultative
//EXAMPLE:          [[snappview sharedInstance] getSnappviewUIAccelerometerDelegate];
- (NSObject <UIAccelerometerDelegate> *) getSnappviewUIAccelerometerDelegate;



////////////////////////////////////////////////////////////////////////////////
//DESCRIPTION:      Returns your key (formatted like u0p0.0000000000000.0000000)
//USAGE:            Facultative
//EXAMPLE:          NSString * k = [[snappview sharedInstance] getAppKey];
- (NSString*) getAppKey;



////////////////////////////////////////////////////////////////////////////////
//DESCRIPTION:      Returns the snappview singleton instance
//USAGE:            Facultative
//EXAMPLE:          snappview * s = [snappview sharedInstance];
+ (snappview*) sharedInstance;



@end
