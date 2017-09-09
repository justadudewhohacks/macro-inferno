const { expect } = require('chai');
const dut = require('../dut');
const {
  assertErrorMsg,
  getArgTypeErrMsg,
  values
} = require('./utils');

const {
  aBool, aNumber, anInt, anUint, aString, anArray, anObject,
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
        [aNumber, anInt, anUint, aString, anObject, anArray].forEach((val) => {
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
        [aBool, aString, anObject, anArray].forEach((val) => {
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
        [aBool, aNumber, aString, anObject, anArray].forEach((val) => {
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
        [aBool, aNumber, anInt, aString, anObject, anArray].forEach((val) => {
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
        [aBool, aNumber, anInt, anUint, anObject, anArray].forEach((val) => {
          assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, 'STRING'));
        });
      });

      it('should return cast and return uint value', () => {
        expect(dut[method](aString)).to.equal(aString);
      });
    });

    describe('arg 0 is array', () => {
      const method = 'arg0IsArray';
      it('should require arg 0', () => {
        assertErrorMsg(() => dut[method](), getArgTypeErrMsg(method, 0, 'ARRAY'));
      });

      it('should throw type error', () => {
        [aBool, aNumber, anInt, anUint, aString, anObject].forEach((val) => {
          assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, 'ARRAY'));
        });
      });

      it('should return cast and return array', () => {
        expect(dut[method](anArray)).to.equal(anArray);
      });
    });

    describe('arg 0 is object', () => {
      const method = 'arg0IsObject';
      it('should require arg 0', () => {
        assertErrorMsg(() => dut[method](), getArgTypeErrMsg(method, 0, 'OBJECT'));
      });

      it('should throw type error', () => {
        [aBool, aNumber, anInt, anUint, aString, anArray].forEach((val) => {
          assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, 'OBJECT'));
        });
      });

      it('should return cast and return object', () => {
        expect(dut[method](anObject)).to.equal(anObject);
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
        [aNumber, anInt, anUint, aString, anObject, anArray].forEach((val) => {
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
        [aBool, aString, anObject, anArray].forEach((val) => {
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
        [aBool, aNumber, aString, anObject, anArray].forEach((val) => {
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
        [aBool, aNumber, anInt, aString, anObject, anArray].forEach((val) => {
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
        [aBool, aNumber, anInt, anUint, anObject, anArray].forEach((val) => {
          assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, 'STRING'));
        });
      });

      it('should return default value', () => {
        expect(dut[method]()).to.equal(aStringDefault);
      });
    });

    describe('arg 0 is optional array', () => {
      const method = 'arg0IsOptArray';
      it('should NOT require arg 0', () => {
        expect(() => dut[method]()).not.to.throw();
      });

      it('should throw type error', () => {
        [aBool, aNumber, anInt, anUint, aString, anObject].forEach((val) => {
          assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, 'ARRAY'));
        });
      });

      it('should return default value', () => {
        const defaultArr = dut[method]();
        expect(defaultArr).to.be.an('array').lengthOf(1);
        expect(defaultArr[0]).to.equal(true);
      });
    });

    describe('arg 0 is optional object', () => {
      const method = 'arg0IsOptObject';
      it('should NOT require arg 0', () => {
        expect(() => dut[method]()).not.to.throw();
      });

      it('should throw type error', () => {
        [aBool, aNumber, anInt, anUint, aString, anArray].forEach((val) => {
          assertErrorMsg(() => dut[method](val), getArgTypeErrMsg(method, 0, 'OBJECT'));
        });
      });

      it('should return default value', () => {
        const defaultObj = dut[method]();
        expect(defaultObj).to.have.property('default').to.equal(true);
      });
    });
  });
});
