let testConfig = Firebase.config(
    ~projectId="metal-air-192104",
    ~databaseURL="https://metal-air-192104.firebaseio.com",
  ()
);

let fb = Firebase.initializeApp(~config=testConfig);
let fs = Firebase.firestore(fb); 
Firebase.Firestore.settings(fs, [%bs.obj {
  timestampsInSnapshots: true
}]);

/* GET TEST */
Firebase.Firestore.collection(fs, "teams")
|. Firebase.Firestore.CollectionReference.doc("TBE648WHM")
|. Firebase.Firestore.DocumentReference.get
|> Js.Promise.then_(value => {
  let data = Firebase.Firestore.DocumentSnapshot.data(value);
  let team_id = data##team_id;
  Js.log(team_id); 
  Js.Promise.resolve(); 
});

/* SET TEST */
let update  = [%bs.obj {
  info: {author: "asdfsdf"}
}];

let testDocRef = Firebase.Firestore.collection(fs, "teams")
|. Firebase.Firestore.CollectionReference.doc("TEST")
|. Firebase.Firestore.DocumentReference.set(update); 

/* ADD TEST */
/* let addInfo = [%bs.obj {
  testField: "hi",
  someInt: 2342
}];

let testDocRef = Firebase.Firestore.collection(fs, "teams")
|. Firebase.Firestore.CollectionReference.add(addInfo)
|> Js.Promise.then_(value => {
  let id = Firebase.Firestore.DocumentReference.id(value);
  Js.log(id); 
  Js.Promise.resolve(); 
});   */