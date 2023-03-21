import {execa} from 'execa';

export default defineEventHandler(async (event) => {
  const query = getQuery(event)

  if (typeof query?.input !== 'string') {
    throw createError({
      statusCode: 400,
      statusMessage: 'Bad Request',
      message: 'Missing query',
    })
  }

  let reversed = '';
  try {
    const { stdout } = await execa('./bin/revc', [query.input]);
    reversed = stdout.trim();
  } catch (error) {
    console.log(error);
    throw createError({
      statusCode: 400,
      statusMessage: 'Bad Request',
      message: 'Missing query',
    })
  }
  return reversed
})