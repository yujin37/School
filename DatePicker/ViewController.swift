//
//  ViewController.swift
//  DatePicker
//
//  Created by 최유진 on 2022/11/10.
//

import UIKit

class ViewController: UIViewController {
    let interval = 1.0
    var count = 0
    
    @IBOutlet var lblCurrentTime: UILabel!
    @IBOutlet var lblPickerTime: UILabel!
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        Timer.scheduledTimer(timeInterval: interval, target: self, selector: #selector(self.updateTime), userInfo: nil, repeats: true)
    }

    @IBAction func changeDatePicker(_ sender: UIDatePicker) {
        let datePickerView: UIDatePicker = sender
        let formatter: DateFormatter = DateFormatter()
        formatter.dateFormat = "yyyy-MM-dd HH:mm EEE"
        lblPickerTime.text = "선택시간: "+formatter.string(from: datePickerView.date)
    }
    @objc func updateTime(){
        let date = Date()
        let formatter = DateFormatter()
        
        formatter.dateFormat = "yyyy-MM-dd HH:mm:ss EEE"
        lblCurrentTime.text = "현재시간: " + formatter.string(from: date) + "\n경과시간(초): " + String(self.count)
        self.count = self.count+1
    }
    
}

