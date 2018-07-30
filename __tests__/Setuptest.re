[@bs.module "fs"] external readFileSync : string => string = "readFileSync";

type jsonConfig = {
  projectId: string,
  databaseURL: string,
};

module Decode = {
  let config = (json) =>
    Json.Decode.{
      projectId: json |> field("projectId", string),
      databaseURL: json |> field("databaseURL", string),
    };
};

let firebaseSecretsPath = "__tests__/secrets/firebase.json";

let jsonConfig = firebaseSecretsPath 
  |> readFileSync 
  |> Json.parseOrRaise 
  |> Decode.config;

let config = Firebase.config(~projectId=jsonConfig.projectId, ~databaseURL=jsonConfig.databaseURL, ());

open Jest;
open Expect;
open! Expect.Operators;

describe("Setuptest", () => {
  describe(".config", () => {
    let subject = config;
    test("should generate an object with the correct projectId", () =>
      expect(subject |. Firebase.projectIdGet) |> toContainString("-")
    );

    test("should generate an object with the correct databaseURL", () => 
      expect(subject |. Firebase.databaseURLGet) |> toContainString("http")
    );
  });
});