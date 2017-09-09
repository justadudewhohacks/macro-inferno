const { expect } = require('chai');
const dut = require('../dut');
const {
  assertErrorMsg,
  getArgTypeErrMsg,
  values
} = require('./utils');

const {
  aBool, aNumber, anInt, anUint, aString, anEmptyObject, anEmptyArray,
  aBoolDefault, aNumberDefault, anIntDefault, anUintDefault, aStringDefault
} = values;

describe('ff_args - argument checking and casting', () => {
  describe('required args', () => {
    describe('arg 0 is bool', () => {
      const method = 'arg0IsBool';
      it('should require arg 0', () => {
        assertErrorMsg(() => dut[method](), getArgTypeErrMsg(method, 0, 'BOOL'));
      });

      it('should throw type error', () => {
        [aNumber, anInt, anUint, aString, anEmptyObject, anEmptyArray].forEach((val) => {
          assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, 'BOOL'));
        });
      });

      it('should return cast and return number value', () => {
        expect(dut[method](aBool)).to.equal(aBool);
      });
    });

    describe('arg 0 is number', () => {
      const method = 'arg0IsNumber';
      it('should require arg 0', () => {
        assertErrorMsg(() => dut[method](), getArgTypeErrMsg(method, 0, 'NUMBER'));
      });

      it('should throw type error', () => {
        [aBool, aString, anEmptyObject, anEmptyArray].forEach((val) => {
          assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, 'NUMBER'));
        });
      });

      it('should return cast and return number value', () => {
        expect(dut[method](aNumber)).to.equal(aNumber);
      });

      it('should return cast and return int value', () => {
        expect(dut[method](anInt)).to.equal(anInt);
      });

      it('should return cast and return uint value', () => {
        expect(dut[method](anUint)).to.equal(anUint);
      });
    });

    describe('arg 0 is int', () => {
      const method = 'arg0IsInt';
      it('should require arg 0', () => {
        assertErrorMsg(() => dut[method](), getArgTypeErrMsg(method, 0, 'INT'));
      });

      it('should throw type error', () => {
        [aBool, aNumber, aString, anEmptyObject, anEmptyArray].forEach((val) => {
          assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, 'INT'));
        });
      });

      it('should return cast and return int value', () => {
        expect(dut[method](anInt)).to.equal(anInt);
      });

      it('should return cast and return uint value', () => {
        expect(dut[method](anUint)).to.equal(anUint);
      });
    });

    describe('arg 0 is uint', () => {
      const method = 'arg0IsUint';
      it('should require arg 0', () => {
        assertErrorMsg(() => dut[method](), getArgTypeErrMsg(method, 0, 'UINT'));
      });

      it('should throw type error', () => {
        [aBool, aNumber, anInt, aString, anEmptyObject, anEmptyArray].forEach((val) => {
          assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, 'UINT'));
        });
      });

      it('should return cast and return uint value', () => {
        expect(dut[method](anUint)).to.equal(anUint);
      });
    });

    describe('arg 0 is string', () => {
      const method = 'arg0IsString';
      it('should require arg 0', () => {
        assertErrorMsg(() => dut[method](), getArgTypeErrMsg(method, 0, 'STRING'));
      });

      it('should throw type error', () => {
        [aBool, aNumber, anInt, anUint, anEmptyObject, anEmptyArray].forEach((val) => {
          assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, 'STRING'));
        });
      });

      it('should return cast and return uint value', () => {
        expect(dut[method](aString)).to.equal(aString);
      });
    });
  });

  describe('optional args', () => {
    describe('arg 0 is optional bool', () => {
      const method = 'arg0IsOptBool';
      it('should NOT require arg 0', () => {
        expect(() => dut[method]()).not.to.throw();
      });

      it('should throw type error', () => {
        [aNumber, anInt, anUint, aString, anEmptyObject, anEmptyArray].forEach((val) => {
          assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, 'BOOL'));
        });
      });

      it('should return default value', () => {
        expect(dut[method]()).to.equal(aBoolDefault);
      });
    });

    describe('arg 0 is optional number', () => {
      const method = 'arg0IsOptNumber';
      it('should NOT require arg 0', () => {
        expect(() => dut[method]()).not.to.throw();
      });

      it('should throw type error', () => {
        [aBool, aString, anEmptyObject, anEmptyArray].forEach((val) => {
          assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, 'NUMBER'));
        });
      });

      it('should return default value', () => {
        expect(dut[method]()).to.equal(aNumberDefault);
      });
    });

    describe('arg 0 is optional int', () => {
      const method = 'arg0IsOptInt';
      it('should NOT require arg 0', () => {
        expect(() => dut[method]()).not.to.throw();
      });

      it('should throw type error', () => {
        [aBool, aNumber, aString, anEmptyObject, anEmptyArray].forEach((val) => {
          assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, 'INT'));
        });
      });

      it('should return default value', () => {
        expect(dut[method]()).to.equal(anIntDefault);
      });
    });

    describe('arg 0 is optional uint', () => {
      const method = 'arg0IsOptUint';
      it('should NOT require arg 0', () => {
        expect(() => dut[method]()).not.to.throw();
      });

      it('should throw type error', () => {
        [aBool, aNumber, anInt, aString, anEmptyObject, anEmptyArray].forEach((val) => {
          assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, 'UINT'));
        });
      });

      it('should return default value', () => {
        expect(dut[method]()).to.equal(anUintDefault);
      });
    });

    describe('arg 0 is optional string', () => {
      const method = 'arg0IsOptString';
      it('should NOT require arg 0', () => {
        expect(() => dut[method]()).not.to.throw();
      });

      it('should throw type error', () => {
        [aBool, aNumber, anInt, anUint, anEmptyObject, anEmptyArray].forEach((val) => {
          assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, 'STRING'));
        });
      });

      it('should return default value', () => {
        expect(dut[method]()).to.equal(aStringDefault);
      });
    });
  });
});
