let testConfig = [%bs.obj {
  projectId: "metal-air-192104",
  databaseURL: "https://metal-air-192104.firebaseio.com"
}];

let fb = Firebase.initializeApp(testConfig);
let fs = Firebase.firestore(fb); 
Firestore.settings(fs, [%bs.obj {
  timestampsInSnapshots: true
}]);

/* GET TEST */
Firestore.collection(fs, "teams")
|. Firestore.CollectionReference.doc("TBE648WHM")
|. Firestore.DocumentReference.get
|> Js.Promise.then_(value => {
  let data = Firestore.DocumentSnapshot.data(value);
  let team_id = data##team_id;
  Js.log(team_id); 
  Js.Promise.resolve(); 
});

/* SET TEST */
let update  = [%bs.obj {
  info: {author: "adfadsfasd"}
}];

let testDocRef = Firestore.collection(fs, "teams")
|. Firestore.CollectionReference.doc("TEST")
|. Firestore.DocumentReference.set(update); 

/* ADD TEST */
/* let addInfo = [%bs.obj {
  testField: "hi!!",
  someInt: 2342
}];

let testDocRef = Firestore.collection(fs, "teams")
|. Firestore.CollectionReference.add(addInfo)
|> Js.Promise.then_(value => {
  let id = Firestore.DocumentReference.id(value);
  Js.log(id); 
  Js.Promise.resolve(); 
});   */