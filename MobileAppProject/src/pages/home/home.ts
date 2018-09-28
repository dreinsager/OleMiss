import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { AlertController } from 'ionic-angular';


@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})
export class HomePage {
  constructor(public navCtrl: NavController,public alertCtrl: AlertController) {

  }
  showAlert() {
    const alert = this.alertCtrl.create({
      title: 'To Dice!',
      subTitle: 'This will take you to the dice roller page where we will make a random number generator to output certain numbers on the die',
      buttons: ['OK']
    });
    alert.present();
  }

}
