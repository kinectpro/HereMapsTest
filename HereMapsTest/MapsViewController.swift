//
//  MapViewController.swift
//  GMTest
//

//  Created by Alex Dontsov on 31.10.16.
//  Copyright © 2016 Kinect.Pro. All rights reserved.
//

import UIKit
//import GoogleMaps

import CoreLocation
@objc
protocol MapsViewControllerDelegate {
    @objc optional func toggleMenu()
}

class MapsViewController: UIViewController {
    var delegate: MapsViewControllerDelegate?
    var mapView = NMAMapView()
    
    var locationManager = CLLocationManager()
    let defaultMapZoom : Float = 14
    var mapCircle = NMAMapCircle()
    override func viewDidLoad() {
        super.viewDidLoad()
        
        locationManager.delegate = self
        locationManager.requestWhenInUseAuthorization()
        locationManager.startUpdatingLocation()
        
        mapView = NMAMapView()
        mapView.useHighResolutionMap = true
        mapView.zoomLevel = defaultMapZoom
        self.view = mapView
    }
    
    // MARK: Button actions
    @IBAction func menuTapped(sender: AnyObject) {
        delegate?.toggleMenu?()
    }
    
}

extension MapsViewController: MenuViewControllerDelegate {
    func menuItemSelected(item: City) {
        delegate?.toggleMenu?()
        if !(item.title == currentLocation) {
            
            let coordinates = NMAGeoCoordinates(latitude: item.coordinates.latitude, longitude: item.coordinates.longitude)
            mapView.set(geoCenter: coordinates, animation: .linear)
            let marker = NMAMapMarker(geoCoordinates: coordinates, image: UIImage(named: "Marker-48.png"))!
            marker.title = item.title
            mapView.add(marker)
        } else {
            locationManager.startUpdatingLocation()
        }
    }
}

extension MapsViewController: CLLocationManagerDelegate {
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        let location = locations.last
        let coordinates = NMAGeoCoordinates(latitude: (location?.coordinate.latitude)!, longitude: (location?.coordinate.longitude)!)
        
        mapView.set(geoCenter: coordinates, animation: .linear)
        mapView.remove(mapCircle)
        mapCircle = NMAMapCircle(coordinates: coordinates, radius: 50)
        mapView.add(mapCircle)
        
        //Finally stop updating location otherwise it will come again and again in this delegate
        self.locationManager.stopUpdatingLocation()
        
    }
}
