open Jest;
open Expect;
open! Expect.Operators;

/**
 * Not sure how to test? See this package for an example!
 *
 * https://github.com/Schniz/bs-faker/blob/master/__tests__/Fakertest.re
 */
describe("Firebase", () => {
  describe("config", () => {
    let subject = Firebase.config(~projectId="blah", ~databaseURL="halb", ());
    test("should generate an object with the correct projectId", () =>
      expect(subject |. Firebase.projectIdGet) === "blah"
    );

    test("should generate an object with the correct databaseURL", () =>
      expect(subject |. Firebase.databaseURLGet) === "halb"
    );
  });

  describe("firebase", () => {
    test("should be ok", () =>
      expect(() => Setuptest.config |> Firebase.initializeApp) |> not_ |> toThrow
    );
  });
});

/* GET TEST */
/* Firestore.collection(fs, "teams")
|. Firestore.CollectionReference.doc("TBE648WHM")
|. Firestore.DocumentReference.get
|> Js.Promise.then_(value => {
  let data = Firestore.DocumentSnapshot.data(value);
  let team_id = data##team_id;
  Js.log(team_id);
  Js.Promise.resolve();
}); */

/* SET TEST */
/* let update  = [%bs.obj {
  info: {author: "adfadsfasd"}
}];

let testDocRef = Firestore.collection(fs, "teams")
|. Firestore.CollectionReference.doc("TEST")
|. Firestore.DocumentReference.set(update);  */

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
