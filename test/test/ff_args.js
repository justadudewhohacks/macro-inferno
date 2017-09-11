const { expect } = require('chai');
const dut = require('../dut');
const {
  assertErrorMsg,
  getArgTypeErrMsg,
  getTypeErrMsg,
  values
} = require('./utils');

const {
  aBool, aNumber, anInt, anUint, aString, anArray, anObject,
  aBoolDefault, aNumberDefault, anIntDefault, anUintDefault, aStringDefault
} = values;

const generateRequiredArgTests = ({ type, throwForTypes, validValues }) => {
  describe(`arg 0 is ${type}`, () => {
    const method = `arg0Is${`${type[0].toUpperCase()}${type.substr(1)}`}`;
    it('should require arg 0 to be', () => {
      assertErrorMsg(() => dut[method](), getArgTypeErrMsg(method, 0, type.toUpperCase()));
    });

    it('should throw type error', () => {
      throwForTypes.forEach((val) => {
        assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, type.toUpperCase()));
      });
    });

    validValues.forEach((val) => {
      it(`should cast and return '${val}'`, () => {
        expect(dut[method](val)).to.equal(val);
      });
    });
  });
};

const generateOptionalArgTests = ({ type, throwForTypes, defaultVal, assertDefaultVal }) => {
  describe(`arg 0 is optional ${type}`, () => {
    const method = `arg0IsOpt${`${type[0].toUpperCase()}${type.substr(1)}`}`;
    it('should NOT require arg 0', () => {
      expect(() => dut[method]()).not.to.throw();
    });

    it('should throw type error', () => {
      throwForTypes.forEach((val) => {
        assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, type.toUpperCase()));
      });
    });

    it('should return default value', () => {
      const returnedDefaultVal = dut[method]();
      if (assertDefaultVal !== undefined) {
        assertDefaultVal(returnedDefaultVal);
      } else {
        expect(returnedDefaultVal).to.equal(defaultVal);
      }
    });
  });
};

const generateArrayArgTests = ({ type, throwForTypes, validValues }) => {
  describe(`arg 0 is array of ${type}`, () => {
    const method = `arg0Is${`${type[0].toUpperCase()}${type.substr(1)}`}Array`;
    const validArray = Array(5).fill(validValues[0]);
    it('should require arg 0', () => {
      assertErrorMsg(() => dut[method](), getArgTypeErrMsg(method, 0, 'ARRAY'));
    });

    it('should throw if is not an array', () => {
      [aBool, aNumber, anInt, anUint, aString, anObject].forEach((val) => {
        assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, 'ARRAY'));
      });
    });

    it('should throw type error if contains value with invalid type', () => {
      throwForTypes.forEach((val) => {
        const invalidArray = validArray.slice();
        invalidArray.push(val);
        assertErrorMsg(() => dut[method](invalidArray), getTypeErrMsg(type.toUpperCase()));
      });
    });

    it('should unpack, pack and return array', () => {
      const ret = dut[method](validArray);
      expect(ret).to.be.an('array').lengthOf(5);
      expect(ret).to.have.members(validArray);
    });
  });
};

const generateOptionalArrayArgTests = ({ type, throwForTypes, validValues }) => {
  describe(`arg 0 is optional array of ${type}`, () => {
    const method = `arg0IsOpt${`${type[0].toUpperCase()}${type.substr(1)}`}Array`;
    const validArray = Array(5).fill(validValues[0]);
    it('should NOT require arg 0', () => {
      expect(() => dut[method]()).not.to.throw();
    });

    it('should throw if is not an array', () => {
      [aBool, aNumber, anInt, anUint, aString, anObject].forEach((val) => {
        assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, 'ARRAY'));
      });
    });

    it('should throw type error if contains value with invalid type', () => {
      throwForTypes.forEach((val) => {
        const invalidArray = validArray.slice();
        invalidArray.push(val);
        assertErrorMsg(() => dut[method](invalidArray), getTypeErrMsg(type.toUpperCase()));
      });
    });

    it('should unpack, pack and return array', () => {
      const ret = dut[method](validArray);
      expect(ret).to.be.an('array').lengthOf(5);
      expect(ret).to.have.members(validArray);
    });

    it('should return a default value', () => {
      let assertType = (type === 'int' || type === 'uint') ? 'number' : type;
      assertType = assertType === 'bool' ? 'boolean' : assertType;
      const ret = dut[method]();
      expect(ret).to.be.an('array').lengthOf(1);
      expect(ret[0]).to.be.a(assertType);
    });
  });
};

describe('ff_args - argument checking and casting', () => {
  describe('required args', () => {
    generateRequiredArgTests({
      type: 'bool',
      throwForTypes: [aNumber, anInt, anUint, aString, anObject, anArray],
      validValues: [aBool]
    });

    generateRequiredArgTests({
      type: 'number',
      throwForTypes: [aBool, aString, anObject, anArray],
      validValues: [aNumber, anInt, anUint]
    });

    generateRequiredArgTests({
      type: 'int',
      throwForTypes: [aBool, aNumber, aString, anObject, anArray],
      validValues: [anInt, anUint]
    });

    generateRequiredArgTests({
      type: 'uint',
      throwForTypes: [aBool, aNumber, anInt, aString, anObject, anArray],
      validValues: [anUint]
    });

    generateRequiredArgTests({
      type: 'string',
      throwForTypes: [aBool, aNumber, anInt, anUint, anObject, anArray],
      validValues: [aString]
    });

    generateRequiredArgTests({
      type: 'array',
      throwForTypes: [aBool, aNumber, anInt, anUint, aString, anObject],
      validValues: [anArray]
    });

    generateRequiredArgTests({
      type: 'object',
      throwForTypes: [aBool, aNumber, anInt, anUint, aString, anArray],
      validValues: [anObject]
    });
  });

  describe('optional args', () => {
    generateOptionalArgTests({
      type: 'bool',
      throwForTypes: [aNumber, anInt, anUint, aString, anObject, anArray],
      defaultVal: aBoolDefault
    });

    generateOptionalArgTests({
      type: 'number',
      throwForTypes: [aBool, aString, anObject, anArray],
      defaultVal: aNumberDefault
    });

    generateOptionalArgTests({
      type: 'int',
      throwForTypes: [aBool, aNumber, aString, anObject, anArray],
      defaultVal: anIntDefault
    });

    generateOptionalArgTests({
      type: 'uint',
      throwForTypes: [aBool, aNumber, anInt, aString, anObject, anArray],
      defaultVal: anUintDefault
    });

    generateOptionalArgTests({
      type: 'string',
      throwForTypes: [aBool, aNumber, anInt, anUint, anObject, anArray],
      defaultVal: aStringDefault
    });

    generateOptionalArgTests({
      type: 'array',
      throwForTypes: [aBool, aNumber, anInt, anUint, aString, anObject],
      assertDefaultVal: (defaultVal) => {
        expect(defaultVal).to.be.an('array').lengthOf(1);
        expect(defaultVal[0]).to.equal(true);
      }
    });

    generateOptionalArgTests({
      type: 'object',
      throwForTypes: [aBool, aNumber, anInt, anUint, aString, anArray],
      assertDefaultVal: (defaultVal) => {
        expect(defaultVal).to.have.property('default').to.equal(true);
      }
    });
  });

  describe('array args', () => {
    generateArrayArgTests({
      type: 'bool',
      throwForTypes: [aNumber, anInt, anUint, aString, anObject, anArray],
      validValues: [aBool]
    });

    generateArrayArgTests({
      type: 'number',
      throwForTypes: [aBool, aString, anObject, anArray],
      validValues: [aNumber, anInt, anUint]
    });

    generateArrayArgTests({
      type: 'int',
      throwForTypes: [aBool, aNumber, aString, anObject, anArray],
      validValues: [anInt, anUint]
    });

    generateArrayArgTests({
      type: 'uint',
      throwForTypes: [aBool, aNumber, anInt, aString, anObject, anArray],
      validValues: [anUint]
    });

    generateArrayArgTests({
      type: 'string',
      throwForTypes: [aBool, aNumber, anInt, anUint, anObject, anArray],
      validValues: [aString]
    });

    generateArrayArgTests({
      type: 'array',
      throwForTypes: [aBool, aNumber, anInt, anUint, aString, anObject],
      validValues: [anArray]
    });

    generateArrayArgTests({
      type: 'object',
      throwForTypes: [aBool, aNumber, anInt, anUint, aString, anArray],
      validValues: [anObject]
    });
  });

  describe('optional array args', () => {
    generateOptionalArrayArgTests({
      type: 'bool',
      throwForTypes: [aNumber, anInt, anUint, aString, anObject, anArray],
      validValues: [aBool]
    });

    generateOptionalArrayArgTests({
      type: 'number',
      throwForTypes: [aBool, aString, anObject, anArray],
      validValues: [aNumber, anInt, anUint]
    });

    generateOptionalArrayArgTests({
      type: 'int',
      throwForTypes: [aBool, aNumber, aString, anObject, anArray],
      validValues: [anInt, anUint]
    });

    generateOptionalArrayArgTests({
      type: 'uint',
      throwForTypes: [aBool, aNumber, anInt, aString, anObject, anArray],
      validValues: [anUint]
    });

    generateOptionalArrayArgTests({
      type: 'string',
      throwForTypes: [aBool, aNumber, anInt, anUint, anObject, anArray],
      validValues: [aString]
    });

    generateOptionalArrayArgTests({
      type: 'array',
      throwForTypes: [aBool, aNumber, anInt, anUint, aString, anObject],
      validValues: [anArray]
    });

    generateOptionalArrayArgTests({
      type: 'object',
      throwForTypes: [aBool, aNumber, anInt, anUint, aString, anArray],
      validValues: [anObject]
    });
  });
});
