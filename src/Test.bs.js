// Generated by BUCKLESCRIPT VERSION 4.0.1, PLEASE EDIT WITH CARE
'use strict';

var Firebase = require("firebase");

var testConfig = {
  projectId: "metal-air-192104",
  databaseURL: "https://metal-air-192104.firebaseio.com"
};

var fb = Firebase.initializeApp(testConfig);

var fs = fb.firestore();

fs.settings({
      timestampsInSnapshots: true
    });

fs.collection("teams").doc("TBE648WHM").get().then((function (value) {
        var data = value.data();
        var team_id = data.team_id;
        console.log(team_id);
        return Promise.resolve(/* () */0);
      }));

var update = {
  info: {
    author: "adfadsfasd"
  }
};

fs.collection("teams").doc("TEST").set(update);

var testDocRef = /* () */0;

exports.testConfig = testConfig;
exports.fb = fb;
exports.fs = fs;
exports.update = update;
exports.testDocRef = testDocRef;
/* fb Not a pure module */
