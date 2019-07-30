//
//  ViewController.swift
//  stepTracker
//
//  Created by Alan on 4/5/2019.
//  Copyright © 2019 Alan Tsui. All rights reserved.
//

import UIKit
import HealthKit

class ViewController: UIViewController {

    //We need to access Health Store
    let healthStore = HKHealthStore();
    
    @IBOutlet weak var stepLabel: UILabel!
    
    @IBOutlet weak var walkedLabel: UILabel!
    
    @IBOutlet weak var remainLabel: UILabel!
    
    //Retrieve step count
    func updateDailyStepCount() {
        
        //Get number of steps today
        let calendar = Calendar.current
        let now = Date()
        let dateComponents = calendar.dateComponents([.year,.month,.day], from: now)
        
        //today 00:00
        guard let startDate = calendar.date(from: dateComponents) else {
            fatalError("Failed to create start date")
        }
        
        //tomorrow 00:00
        guard var endDate = calendar.date(byAdding:.day,value:1,to:startDate) else {
            fatalError("Failed to create end date")
        }
        
        // -1s in end date -> 11:59 today
        endDate = endDate.addingTimeInterval(-1)
        
        // Health Kit samples range from [startDate...endDate]
        let todayOnlyPredicate = HKQuery.predicateForSamples(withStart: startDate, end: endDate, options: [])
        
        // Get the "cumulate sum" of "step count" in range "todayOnlyPredicate"
        let stepStatQuery = HKStatisticsQuery(quantityType: HKObjectType.quantityType(forIdentifier: .stepCount)!, quantitySamplePredicate: todayOnlyPredicate, options: [.cumulativeSum]){
            (query,result,error) in
            
            //After getting data from steps
            if error != nil {
                print("Failed to retrieve the step count. The error was \(error!.localizedDescription)")
            }
            
            //If result is 0 give no step count
            guard let result = result else {
                print("No Step Count")
                return
            }
            
            // let totalStep = sum of result
            if let totalSteps = result.sumQuantity(){
                
                //print the result
                print(totalSteps)
                
                //Get the count from the total steps data set and sum it up to integer
                let totalStepCount = Int(totalSteps.doubleValue(for: .count()))
                var remainingStepCount = 10000 - totalStepCount
                
                //Set it to 0 if not init
                if remainingStepCount < 0 {
                    remainingStepCount = 0
                }
                
                //Print the total Count
                print("Total steps: \(totalStepCount)")
                print("Remaining steps: \(remainingStepCount)")
                
                
                //Format the count 9230 -> 9,230
                let formatter = NumberFormatter()
                formatter.usesGroupingSeparator = true
                formatter.numberStyle = .decimal
                
                //Update count to label
                DispatchQueue.main.async {
                    //self.stepLabel.text = "\(totalStepCount)"
                    self.stepLabel.text = formatter.string(from: totalStepCount as NSNumber)
                    
                    //Get the message
                    let remainStepText = NSMutableAttributedString(attributedString: self.remainLabel.attributedText!)
                    
                    if let index = remainStepText.string.range(of: "XXX")?.lowerBound {
                        let distance = remainStepText.string.distance(from: remainStepText.string.startIndex, to: index)
                       
                        remainStepText.replaceCharacters(in: NSRange(location: distance, length: 3), with: formatter.string(from: remainingStepCount as NSNumber) ?? "")
                    }
                    
                    self.remainLabel.attributedText = remainStepText
                    
                }
            }
        }
        
        healthStore.execute(stepStatQuery)
        
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        
        //Authorize when app start
        
        //Block device with no Health Kit
        guard HKHealthStore.isHealthDataAvailable() else {
            fatalError("Your device doesn't support HealthKit")
        }
        
        //We need "Walking & Running" and "Step count"
        let healthTypesToRead = Set([HKObjectType.quantityType(forIdentifier: .distanceWalkingRunning)!,HKObjectType.quantityType(forIdentifier: .stepCount)!])
        
        //Call the apple Authorizer
        healthStore.requestAuthorization(toShare: nil, read: healthTypesToRead){
            (success,error) in
            
            if !success {
                print(error.debugDescription)
            }
        }
        
        updateDailyStepCount()
        
    }


}

