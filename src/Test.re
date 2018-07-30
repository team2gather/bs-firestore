let fb = Firebase.initializeApp({
  "projectId": "metal-air-192104",
  "databaseURL": "https://metal-air-192104.firebaseio.com"
});
let fs = Firebase.firestore(fb); 
Firestore.settings(fs, {
  "timestampsInSnapshots": true
});

/* GET TEST */
Firestore.collection(fs, "teams")
|. Firestore.doc("TBE648WHM")
|. Firestore.DocumentReference.get
|> Js.Promise.then_(value => {
  let data = Firestore.DocumentSnapshot.data(value);
  let team_id = data##team_id;
  Js.log(team_id); 
  Js.Promise.resolve(); 
});

/* SET TEST */
let update  = {
  "info": {author: "adfadsfasd"}
};

let testDocRef = Firestore.collection(fs, "teams")
|. Firestore.doc("TEST")
|. Firestore.DocumentReference.set(update); 

/* ADD TEST */
let addInfo = {
  "testField": "hi!!",
  "someInt": 2342
};

/* let testDocRef = Firestore.collection(fs, "teams")
|. Firestore.CollectionReference.add(addInfo)
|> Js.Promise.then_(value => {
  let id = Firestore.DocumentReference.id(value);
  Js.log(id); 
  Js.Promise.resolve(); 
});   */

/* SNAPSHOT */
/* let unsub = Firestore.collection(fs, "maps")
|. Firestore.doc("HVAPqdFNWpOSh8neZWbu")
|. Firestore.DocumentReference.onSnapshot((snapshot) => {
  let data = Firestore.DocumentSnapshot.data(snapshot);
  Js.log(data);
}, (error) => {
  Js.log(error);
});
unsub(); */

let unsub2 = Firestore.collection(fs, "maps")
|. Firestore.doc("HVAPqdFNWpOSh8neZWbu")
|. Firestore.collection("attendees")
|. Firestore.CollectionReference.onSnapshot((snapshot) => {
  let docs = Firestore.QuerySnapshot.docs(snapshot);
  Array.map((doc) => {
    Js.log(Firestore.DocumentSnapshot.data(doc));
  }, docs);
}, (error) => {
  Js.log(error);
});
/* unsub2(); */
